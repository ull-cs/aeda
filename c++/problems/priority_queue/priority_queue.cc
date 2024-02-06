#include "priority_queue.h"

using namespace std;

PriorityQueue::PriorityQueue() {
  size = 0;
}

void PriorityQueue::enqueue(int value, int priority) {
  elements[size].value = value;
  elements[size].priority = priority;
  size++;  
}

Element PriorityQueue::peek() {
  int highestPriorityIndex = indexElementWithHighestPriority();
  return elements[highestPriorityIndex];
}

void PriorityQueue::dequeue() {
  const int highestPriorityIndex = indexElementWithHighestPriority();
  for (int i = highestPriorityIndex; i < size - 1; i++) {
    elements[i] = elements[i + 1];
  }
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