#include <iostream>

using namespace std;

class Base {
 public:
  Base() {
    cout << "Base. Constructor\n";
  }
  virtual ~Base() {
    cout << "Base. Destructor\n";
  }
};

class Derived : public Base {
 public:
  Derived() {
    cout << "Derived. Constructor\n";
  }
  virtual ~Derived() {
    cout << "Derived. Destructor\n";
  }
};

int main() {
  Derived *derived = new Derived();
  Base *base = derived;
  delete base;
  return 0;
}
