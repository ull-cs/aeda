#ifndef STACK
#define STACK

#define MAX 1000

class Stack {
 public:
  Stack();
  bool push(int);
  int pop();
  int peek();
  bool isEmpty();

 private:
  int top;
  int elements[MAX];
};

#endif