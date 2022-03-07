#include <iostream>

#define MAXIMUM(a, b) ((a > b) ? a : b)

int main() {
  const int kNumber1 = 1;
  const int kNumber2 = 5;
  std::cout << "The largest value between " << kNumber1 << " and " << kNumber2 << " is " << MAXIMUM(kNumber1, kNumber2) << std::endl;
  return 0;
}