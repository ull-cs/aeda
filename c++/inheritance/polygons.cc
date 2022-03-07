#include <iostream>

using namespace std;

class Polygon {
 public:
  void setValues(int width, int height) {
    width_ = width;
    height_ = height;
  }

 protected:
  int width_;
  int height_;
};

class Rectangle : public Polygon {
 public:
  int area() {
    return (width_ * height_);
  }
};

class Triangle : public Polygon {
 public:
  int area() {
    return (width_ * height_) / 2;
  }
};

int main() {
  Rectangle rectangle;
  Triangle triangle;
  rectangle.setValues(4, 5);
  triangle.setValues(4, 5);
  cout << "Area: " << rectangle.area() << '\n';
  cout << "Area: " << triangle.area() << '\n';
  return 0;
}