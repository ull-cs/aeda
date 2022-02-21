#include <iostream>
#include <stdlib.h>
#include "stack.h"

using namespace std;

int main() {
  Stack stack;
  for (int i = 0; i < 10; i++) {
    const int randomNumber = rand() % 10 + 1;
    if (stack.push(randomNumber)) {
      cout << randomNumber << " has been pushed" << endl;
    }
  }
  cout << "Elements present in stack: ";
  while (!stack.isEmpty()) {
    cout << stack.peek() << " ";
    stack.pop();
  }
  cout << endl;
  return 0;
}
