#include <iostream>
#include "p1.h"

using namespace std;

static int f(int);

int f(int x) { 
  return x*x; 
}

void g(int i){ 
  cout << f(i) << endl; 
}
