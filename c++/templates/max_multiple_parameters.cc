#include <iostream>

using namespace std;

template <typename T, typename U>  // '>' must be overloaded
auto Maximum(T x, U y) {
  return (x > y) ? x : y;
}

int main() {
  cout << "Maximum between " << 3 << " and " << 7.5 << " is: " << Maximum(3, 7.5) << endl;
  cout << "Maximum between " << 'p' << " and " << 7.0 << " is: " << Maximum('p', 7.0) << endl;
  cout << "Maximum between " << 5 << " and " << 'e' << " is: " << Maximum(5, 'e') << endl;
  return 0;
}
