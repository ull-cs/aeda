#include <iostream>

using namespace std;

class Base {
 public:
  virtual void Print() {
    cout << "Print base class\n";
  }
  void Show() {
    cout << "Show base class\n";
  }
};

class Derived : public Base {
 public:
  void Print() {
    cout << "Print derived class\n";
  }
  void Show() {
    cout << "Show derived class\n";
  }
};

int main() {
  Base *pointerBase;
  Derived derived;
  pointerBase = &derived;
  // Virtual function, binded at runtime
  pointerBase->Print();
  // Non-virtual function, binded at compile time
  pointerBase->Show();
  return 0;
}
