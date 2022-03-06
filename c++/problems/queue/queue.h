#include "node.h"

#ifndef QUEUE
#define QUEUE

using namespace std;

template <class T>
class Queue {
 public:
  Queue();
  bool isEmpty();
  void push(T v);
  T peek();
  void pop();

 private:
  Node<T> *start;
  Node<T> *end;
};

template <typename T>
Queue<T>::Queue() {
  start = end = NULL;
}

template <typename T>
bool Queue<T>::isEmpty() {
  return start == NULL;
}

template <typename T>
void Queue<T>::push(T v) {
  Node<T> *temp = new Node<T>(v);
  if (isEmpty()) {
    start = end = temp;
  } else {
    end->next = temp;
    end = temp;
  }
}

template <typename T>
T Queue<T>::peek() {
  if (isEmpty())
    return -99999;
  else
    return start->data;
}

template <typename T>
void Queue<T>::pop() {
  if (isEmpty()) {
    cout << "Queue is Empty" << endl;
  } else if (start == end) {
    delete start;
    start = end = NULL;
  } else {
    Node<T> *temp = start;
    start = start->next;
    delete temp;
  }
}

#endif
