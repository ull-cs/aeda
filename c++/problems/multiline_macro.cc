#include <iostream>

#define MACRO(num, str)      \
  {                          \
    std::cout << num;        \
    std::cout << " is";      \
    std::cout << " " << str; \
    std::cout << "\n";       \
  }

int main() {
  int num;
  std::cout << "Enter a number: ";
  std::cin >> num;
  if (num & 1) {  // (num % 2) == 0
    MACRO(num, "Odd");
  } else {
    MACRO(num, "Even");
  }
  return 0;
}
