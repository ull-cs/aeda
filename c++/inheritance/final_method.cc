#include <iostream>

using namespace std;

class Base {
 public:
  virtual void myfun() final {
    cout << "myfun() in Base";
  }
};

class Derived : public Base {
  void myfun() {
    cout << "myfun() in Derived\n";
  }
};

int main() {
  Derived derived;
  Base &base = derived;
  base.myfun();
  return 0;
}
