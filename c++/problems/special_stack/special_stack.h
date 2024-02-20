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
    int currentTop = min.peek();
    if (toInsert < currentTop) {
      min.push(toInsert);
    } else {
      min.push(currentTop);
    }
  }
}

int SpecialStack::pop() {
  int element = Stack::pop();
  min.pop();
  return element;
}

int SpecialStack::getMin() {
  int elementWithMinimumValue = min.peek();
  return elementWithMinimumValue;
}

void SpecialStack::print() {
  Stack::print();
  min.print();
}
