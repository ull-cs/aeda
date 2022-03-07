#include <iostream>

#define FOR(A, B) for (A = 0; A < B; A++)

int main() {
  int i;
  FOR(i, 5) {
    std::cout << "Iteración " << i << " del bucle" << std::endl;
  }
  return 0;
}