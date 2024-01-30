#include <iostream>

using namespace std;

int main() {
  double myDouble = 21.09399;
  float myFloat = 10.20;
  int myInt = (int)myDouble;
  cout << "Value of 'myInt = (int)myDouble' is: " << myInt << endl;
  myInt = (int)myFloat;
  cout << "Value of 'myInt = (int)myFloat' is: " << myInt << endl;
  return 0;
}