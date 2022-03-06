#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "queue_element.h"

#define MAX 1000

class PriorityQueue {
 public:
  PriorityQueue();
  void enqueue(int value, int priority);
  int peek();
  void dequeue();
  bool isEmpty();
  int getSize();

 private:
  int size;
  queue_element elements[MAX];
  int indexElementWithHighestPriority();
};

#endif