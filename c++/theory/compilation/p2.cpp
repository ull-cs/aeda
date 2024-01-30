#include "p2.h"

#include <iostream>

using namespace std;

static int f(int);

int f(int x) {
  return x / 2;
}

void z(int i) {
  cout << f(i) << endl;
}
