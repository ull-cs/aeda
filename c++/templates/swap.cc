#include <iostream>
using namespace std;

template <typename T>
void Swap(T& value1, T& value2) {
  T aux = value1;
  value1 = value2;
  value2 = aux;
}

int main() {
  int int1 = 6, int2 = 3;
  float float1 = 7.2, float2 = 4.5;
  char char1 = 'p', char2 = 'x';
  cout << "Before passing data to function template:" << endl;
  cout << "int1 = " << int1 << ", int2 = " << int2 << endl;
  cout << "float1 = " << float1 << ", float2 = " << float2 << endl;
  cout << "char1 = " << char1 << ", char2 = " << char2 << endl;
  Swap(int1, int2);
  Swap(float1, float2);
  Swap(char1, char2);
  cout << "After passing data to function template:" << endl;
  cout << "int1 = " << int1 << ", int2 = " << int2 << endl;
  cout << "float1 = " << float1 << ", float2 = " << float2 << endl;
  cout << "char1 = " << char1 << ", char2 = " << char2 << endl;
  return 0;
}
