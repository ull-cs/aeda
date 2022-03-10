#include <iostream>

using namespace std;

class Shape {
 public:
  virtual int getArea() = 0;
  void setHeight(int h) {
    height = h;
  }
  void setWidth(int w) {
    width = w;
  }

 protected:
  int height;
  int width;
};

class Rectangle : public Shape {
 public:
  int getArea() {
    return (width * height);
  }
};

class Triangle : public Shape {
 public:
  int getArea() {
    return (width * height) / 2;
  }
};

int main(void) {
  Rectangle rectangle;
  Triangle triangle;
  rectangle.setWidth(5);
  rectangle.setHeight(7);
  // Print the area of the object
  cout << "Total Rectangle area: " << rectangle.getArea() << endl;
  triangle.setWidth(5);
  triangle.setHeight(7);
  // Print the area of the object
  cout << "Total Triangle area: " << triangle.getArea() << endl;
  return 0;
}
