#include "stack.h"

using namespace std;

Stack::Stack() {
  top = -1;
}

bool Stack::push(int elementToPush) {
  if (top >= (MAX - 1)) {
    return false;
  } else {
    elements[++top] = elementToPush;
    return true;
  }
}

int Stack::pop() {
  if (top < 0) {
    return -1;
  } else {
    int retrieved = elements[top--];
    return retrieved;
  }
}

int Stack::peek() {
  if (top < 0) {
    return 0;
  } else {
    int retrieved = elements[top];
    return retrieved;
  }
}

bool Stack::isEmpty() {
  return (top < 0);
}
