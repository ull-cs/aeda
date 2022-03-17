#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> myvector(10);
  try {
    myvector.at(20) = 100;
  } catch (const std::out_of_range& exception) {
    std::cerr << "Out of Range error: " << exception.what() << std::endl;
  }
  return 0;
}
