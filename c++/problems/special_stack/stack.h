#include <stdlib.h>
#include <iostream>

using namespace std;

class Stack {
 public:
  Stack();
  bool isEmpty();
  bool isFull();
  int peek();
  int pop();
  void push(int toInsert);
  void print();

 private:
  static const int max = 100;
  int data[max];
  int top;
};

Stack::Stack() {
  top = -1;
}

bool Stack::isEmpty() {
  if (top == -1) {
    return true;
  }
  return false;
}

bool Stack::isFull() {
  if (top == max - 1) {
    return true;
  }
  return false;
}

int Stack::peek() {
  if (top < 0) {
    return 0;
  } else {
    return data[top];
  }
}

int Stack::pop() {
  if (isEmpty()) {
    cout << "Stack Underflow";
    abort();
  }
  int element = data[top];
  top--;
  return element;
}

void Stack::push(int toInsert) {
  if (isFull()) {
    cout << "Stack Overflow";
    abort();
  }
  top++;
  data[top] = toInsert;
}

void Stack::print() {
  cout << "Stack: ";
  for (int i = 0; i <= top; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}
