#include <iostream>
 
using namespace std;

class Box {
 public:
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
  static int getCount() {
    return objectCount;
  }
 private:
  static int objectCount;
  double length_;
  double breadth_;
  double height_;
};

int Box::objectCount = 0; // initializing the static attribute

int main(void) {
  cout << "Inital Stage Count: " << Box::getCount() << endl;
  Box Box1(3.3, 1.2, 1.5);
  Box Box2(8.5, 6.0, 2.0);
  cout << "Final Stage Count: " << Box::getCount() << endl;
  return 0;
}
