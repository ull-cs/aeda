#include "priority_queue.h"

using namespace std;

PriorityQueue::PriorityQueue() {
  size = 0;
}

void PriorityQueue::enqueue(const Element& toInsert) {
  elements[size].value = toInsert.value;
  elements[size].priority = toInsert.priority;
  size++;  
}

Element PriorityQueue::peek() {
  const int highestPriorityIndex = indexElementWithHighestPriority();
  return elements[highestPriorityIndex];
}

void PriorityQueue::dequeue() {
  const int highestPriorityIndex = indexElementWithHighestPriority();
  elements[highestPriorityIndex] = elements[size - 1];
  size--;
}

bool PriorityQueue::isEmpty() {
  return (size < 1);
}

int PriorityQueue::getSize() {
  return size;
}

int PriorityQueue::indexElementWithHighestPriority() {
  int highestPriorityIndex = 0;
  for (int i = 1; i < size; i++) {
    if (elements[i].priority > elements[highestPriorityIndex].priority) {
      highestPriorityIndex = i;
    }
  }
  return highestPriorityIndex;
}