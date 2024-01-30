#include <iostream>

using namespace std;

class Box {
 public:
  friend void PrintWidth(Box box);
  void SetWidth(double width);

 private:
  double width_;
};

void Box::SetWidth(double width) {
  width_ = width;
}

void PrintWidth(Box box) {
  cout << "Width of box: " << box.width_ << endl;
}

int main() {
  Box box;
  box.SetWidth(10.0);
  PrintWidth(box);
  return 0;
}
