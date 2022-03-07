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

/* Stack's member method to remove an element from it */
int Stack::pop() {
  if (isEmpty()) {
    cout << "Stack Underflow";
    abort();
  }
  int element = data[top];
  top--;
  return element;
}

/* Stack's member method to insert an element to it */
void Stack::push(int toInsert) {
  if (isFull()) {
    cout << "Stack Overflow";
    abort();
  }
  top++;
  data[top] = toInsert;
}

/* A class that supports all the stack
operations and one additional operation getMin() that returns the
minimum element from stack at any time. This class inherits from
the stack class and uses an auxiliary stack that holds minimum elements */
class SpecialStack : public Stack {
 public:
  int pop();
  void push(int toInsert);
  int getMin();

 private:
  Stack min;
};

/* SpecialStack's member method to insert
an element to it. This method makes sure that the min stack is also
updated with appropriate minimum values */
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

/* SpecialStack's member method to remove an element from it. This method
removes top element from min stack also. */
int SpecialStack::pop() {
  int element = Stack::pop();
  min.pop();
  return element;
}

/* SpecialStack's member method to get minimum element from it. */
int SpecialStack::getMin() {
  int element = min.pop();
  min.push(element);
  return element;
}

int main(int argc, char* argv[]) {
  const int kElements = stoi(argv[1]);
  srand(time(NULL));
  SpecialStack stack;
  for (int i = 0; i < kElements; i++) {
    const int randomNumber = rand() % 10 + 1;
    stack.push(randomNumber);
    cout << randomNumber << " has been pushed" << endl;
  }
  cout << "Elements present in stack: ";
  while (!stack.isEmpty()) {
    cout << stack.peek() << " (min=" << stack.getMin() << ") ";
    stack.pop();
  }
  cout << endl;
  return 0;
}
