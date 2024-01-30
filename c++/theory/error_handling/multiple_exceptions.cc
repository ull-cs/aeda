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
        throw 'exception';       // throwing a character as exception
    } catch (const int value) {  // to catch numeric exceptions
      cerr << "Integer exception with value " << value << endl;
    } catch (const char character) {  // to catch character/string exceptions
      cerr << "Character exception with value " << value << endl;
    }
  }
}
