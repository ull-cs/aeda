#include <iostream>

void f(const int a, const float b, const int c = 4, const int d = 5, const int e = 6) {
  std::cout << "f(const int a, const float b, const int c = 4, const int d = 5, const int e = 6)" << std::endl;
}

void f(const int i = 0) {
  std::cout << "f(const int i = 0)" << std::endl;
}

void f(const int a) {
  std::cout << "f(const int a)" << std::endl;
}

void f(const int a, int b = 0) {
  std::cout << "f(const int a, int b = 0)" << std::endl;
}

int main() {
  f();
  //  f(3);
  f(1, 2);     // segunda f
  //  f(1);    // ¿a cuál de las dos se refiere?
  return 0;
}
