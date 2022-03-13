#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> myvector(10);
  try {
    myvector.at(20) = 100;
  } catch (const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
  }
  return 0;
}
