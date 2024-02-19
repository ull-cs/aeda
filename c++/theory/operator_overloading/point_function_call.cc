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
  void Print() {
    cout << "(" << x << "," << y << ")" << endl;
  }

 private:
  int x;
  int y;
};

int main() {
  Point point;
  // Offset this coordinate x with 3 points and coordinate y with 2 points.
  point(3, 2)
  cout << "Point: ";
  point.Print();
  point(5, 9)(-14, 27)(8, 3);
  cout << "Point: ";
  point.Print();
  return 0;
}
