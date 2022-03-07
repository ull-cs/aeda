#include <iostream>

using namespace std;

class Base {
 public:
  void print() {
    cout << "Base Function" << endl;
  }
};

class Derived : public Base {
 public:
  void print() {
    cout << "Derived Function" << endl;
    // call overridden function
    Base::print();
  }
};

int main() {
  Derived derived;
  derived.print();
  return 0;
}
