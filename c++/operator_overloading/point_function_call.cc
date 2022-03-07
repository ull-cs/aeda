#include <iostream>

using namespace std;

class Point {
 public:
  Point() : x(0), y(0) {}
  Point& operator()(int dx, int dy) {
    x += dx;
    y += dy;
    return *this;
  }

 private:
  int x;
  int y;
};

int main() {
  Point pt;
  // Offset this coordinate x with 3 points and coordinate y with 2 points.
  pt(3, 2);
  return 0;
}
