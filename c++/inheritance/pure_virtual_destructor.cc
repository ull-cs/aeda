#include <iostream>

class Base {
 public:
  virtual ~Base() = 0;  // Pure virtual destructor
};

Base::~Base() {
  std::cout << "Pure virtual destructor is called\n";
}

class Derived : public Base {
 public:
  ~Derived() {
    std::cout << "~Derived() is executed\n";
  }
};

int main() {
  Base* base = new Derived();
  delete base;
  return 0;
}
