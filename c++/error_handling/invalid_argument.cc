#include <bitset>
#include <iostream>

int main(void) {
  try {
    std::bitset<5> myBitset(std::string("9848011223"));
  } catch (const std::invalid_argument& exception) {
    std::cerr << "Invalid argument: " << exception.what() << '\n';
  }
  return 0;
}