#include <iostream>

using namespace std;

int main() {
  int data[3] = {-1, 2};
  for (int i = 0; i < 2; i++) {
    int value = data[i];
    try {
      if (value > 0)
        throw value;  // throwing numeric value as exception
      else
        throw 'exception';  // throwing a character as exception
    } catch (...) {         // generalised catch block
      cout << "Special exception" << endl;
    }
  }
  return 0;
}