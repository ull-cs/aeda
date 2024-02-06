#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include "element.h"
#include <iostream>

#define MAX 1000

using namespace std;

class PriorityQueue {
 public:
  PriorityQueue();
  void enqueue(const Element&);
  Element peek();
  void dequeue();
  bool isEmpty();
  int getSize();

  friend std::ostream& operator<<(std::ostream& os, const PriorityQueue& pq) {
	  os << "Priority queue: " << std::endl;
    for (int i = 0; i < pq.size; ++i) {
      os << "Value: " << pq.elements[i].value << ", Priority: " << pq.elements[i].priority << std::endl;
    }
	  os << "size: " << pq.size << std::endl;
	  os << std::endl;
    return os;
  }

 private:
  int size;
  Element elements[MAX];
  int indexElementWithHighestPriority();
};

#endif