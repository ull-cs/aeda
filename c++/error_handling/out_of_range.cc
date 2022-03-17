#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
  std::vector<int> myVector(10);
  try {
    myVector.at(20) = 100;
  } catch (const std::out_of_range& exception) {
    std::cerr << "Out of Range error: " << exception.what() << std::endl;
  }
  return 0;
}
