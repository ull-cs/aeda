#include <iostream>

using namespace std;

class Box {
 public:
  static int objectCount;
  Box(double length = 2.0, double breadth = 2.0, double height = 2.0) {
    cout << "Constructor called." << endl;
    length_ = length;
    breadth_ = breadth;
    height_ = height;
    objectCount++;
  }
  double Volume() {
    return length_ * breadth_ * height_;
  }

 private:
  double length_;
  double breadth_;
  double height_;
};

int Box::objectCount = 0;

int main(void) {
  Box Box1(3.3, 1.2, 1.5);
  Box Box2(8.5, 6.0, 2.0);
  cout << "Total objects: " << Box::objectCount << endl;
  return 0;
}
