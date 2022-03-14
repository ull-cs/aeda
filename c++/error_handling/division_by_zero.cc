#include <iostream>

using namespace std;

int main() {
  int a = 10;
  int b = 0;
  int result;
  try {  // try block activates exception handling
    if (b == 0) {
      throw "Division by zero is not possible";  // throw custom exception
    }  
    result = a / b;
  } catch (const char* message) {  // catches exception
    cerr << message << endl;
  }
  return 0;
}
