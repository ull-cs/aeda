#include <stdlib.h>
#include <iostream>
#include "stack.h"

using namespace std;

class SpecialStack : public Stack {
 public:
  int pop();
  void push(int toInsert);
  int getMin();
  void print();

 private:
  Stack min;
};

void SpecialStack::push(int toInsert) {
  if (isEmpty()) {
    Stack::push(toInsert);
    min.push(toInsert);
  } else {
    Stack::push(toInsert);
    int y = min.pop();
    min.push(y);
    if (toInsert < y) {
      min.push(toInsert);
    } else {
      min.push(y);
    }
  }
}

int SpecialStack::pop() {
  int element = Stack::pop();
  min.pop();
  return element;
}

int SpecialStack::getMin() {
  int element = min.pop();
  min.push(element);
  return element;
}

void SpecialStack::print() {
  Stack::print();
  min.print();
}
