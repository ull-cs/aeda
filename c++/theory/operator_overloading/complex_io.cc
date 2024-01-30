#include <iostream>

using namespace std;

class Complex {
 public:
  Complex(int r = 0, int i = 0) {
    real = r;
    imag = i;
  }
  friend ostream &operator<<(ostream &out, const Complex &c);
  friend istream &operator>>(istream &in, Complex &c);

 private:
  int real, imag;
};

ostream &operator<<(ostream &out, const Complex &c) {
  out << c.real;
  out << "+i" << c.imag << endl;
  return out;
}

istream &operator>>(istream &in, Complex &c) {
  cout << "Enter Real Part ";
  in >> c.real;
  cout << "Enter Imaginary Part ";
  in >> c.imag;
  return in;
}

int main() {
  Complex c1;
  cin >> c1;
  cout << "The complex object is ";
  cout << c1;
  return 0;
}
