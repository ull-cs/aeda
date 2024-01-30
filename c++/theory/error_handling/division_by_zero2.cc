#include <iostream>

using namespace std;

double Division(int a, int b) {
  if (b == 0) {
    throw "Division by zero is not possible";
  }
  return (a / b);
}

int main() {
  int x = 10;
  int y = 0;
  double result = 0;
  try {
    result = Division(x, y);
    cout << result << endl;
  } catch (const char* message) {
    cerr << message << endl;
  }
  return 0;
}
