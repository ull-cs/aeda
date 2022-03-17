#include <iostream>
#include <string>

using namespace std;

class Shape {
  string s_name;

 public:
  Shape(string name) : s_name(name) {}
  virtual void GetInfo() {
    cout << s_name << endl;
  }
};

class Square : public Shape {
 public:
  Square(string S_name, int value)
      : Shape(S_name), side(value) {}
  void GetInfo() {
    cout << "Area of the square is: " << side * side << endl;
  }

 private:
  int side;
};

class Rectangle : public Shape {
 public:
  Rectangle(string S_name, int len, int wid)
      : Shape(S_name), length(len), width(wid) {}
  void GetInfo() {
    cout << "Area of the rectangle is: " << length * width << endl;
  }

 private:
  int length;
  int width;
};

Shape* CreateSquare(string S_name, int value) {
  return new Square(S_name, value);
}

Rectangle* CreateRectangle(string S_name, int len, int wid) {
  return new Rectangle(S_name, len, wid);
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
}