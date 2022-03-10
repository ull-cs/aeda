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

int main(int argc, char* argv[]) {
  const int kElements = stoi(argv[1]);
  srand(time(NULL));
  SpecialStack stack;
  for (int i = 0; i < kElements; i++) {
    const int randomNumber = rand() % 10 + 1;
    stack.push(randomNumber);
    cout << randomNumber << " has been pushed" << endl;
    stack.print();
  }
  cout << "Elements present in stack: ";
  while (!stack.isEmpty()) {
    cout << stack.peek() << " (min=" << stack.getMin() << ") ";
    stack.pop();
  }
  cout << endl;
  return 0;
}
