#include <iostream>

using namespace std;

double Calculator(double a, double b) {
  if (a == b) {
    cerr << "Exit(1)!" << endl;
    exit(1);
  }
  return 1 / (a - b);
}

int main() {
  double x, y, z;
  x = 10;
  y = 10;
  z = Calculator(x, y);
  cout << "x = " << x << " y = " << y << " z = " << z << endl;
  return 0;
}
