#include <iostream>

using namespace std;

template <typename T>  // '>' must be overloaded
T Maximum(T x, T y) {
  return (x > y) ? x : y;
}

int main() {
  cout << "Maximum between " << 3 << " and " << 7 << " is: " << Maximum<int>(3, 7) << endl;
  cout << "Maximum between " << 3.0 << " and " << 7.0 << " is: " << Maximum<double>(3.0, 7.0) << endl;
  cout << "Maximum between " << 'g' << " and " << 'e' << " is: " << Maximum<char>('g', 'e') << endl;
  return 0;
}
