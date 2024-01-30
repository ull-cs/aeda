#include <iostream>
#include <string>

using namespace std;

class Shape {
 public:
  Shape(string name) : name_(name) {}
  virtual void GetInfo() {
    cout << name_ << endl;
  }

 private:
  string name_;
};

class Square : public Shape {
 public:
  Square(string S_name, int value)
      : Shape(S_name), side_(value) {}
  void GetInfo() {
    cout << "Area of the square is: " << side_ * side_ << endl;
  }

 private:
  int side_;
};

class Rectangle : public Shape {
 public:
  Rectangle(string S_name, int length, int width)
      : Shape(S_name), length_(length), width_(width) {}
  void GetInfo() {
    cout << "Area of the rectangle is: " << length_ * width_ << endl;
  }

 private:
  int length_;
  int width_;
};

Shape* CreateSquare(string name, int value) {
  return new Square(name, value);
}

Rectangle* CreateRectangle(string name, int length, int width) {
  return new Rectangle(name, length, width);
}

int main() {
  // quad is the pointer to the parent/ class, it needs to be casted to be used to access the method of the child class.
  Shape* quad = CreateSquare("Quadliteral", 4);
  // Trying to downcast the parent class pointer to the child class pointer.
  Square* square = dynamic_cast<Square*>(quad);
  // dynamic_cast returns returns null if the type to be casted into is a pointer and the cast is unsuccessful.
  if (square) {
    square->GetInfo();
  }
  Rectangle* rectangle = CreateRectangle("Quadliteral", 4, 5);
  // An example of a valid upcasting
  Shape* quad1 = dynamic_cast<Shape*>(rectangle);
  // An example of invalid downcasting
  Square* square1 = dynamic_cast<Square*>(quad1);
  if (square1 == NULL) {
    cout << "Invalid casting." << endl;
  }
  return 0;
}
