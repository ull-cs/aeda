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
  }
};

int main() {
  Derived derived;
  Base* pointer = &derived;
  // Call function of Base class using pointer
  pointer->print();
  return 0;
}
