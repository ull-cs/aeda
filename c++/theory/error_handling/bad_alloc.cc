#include <iostream>

using namespace std;

int main() {
  try {
    int* myArray = new int[5000000000];
    cout << "Element: " << myArray[10000000] << endl;
  } catch (std::bad_alloc& exception) {
    std::cerr << "bad_alloc caught: " << exception.what() << '\n';
  }
  return 0;
}