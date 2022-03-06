#include "priority_queue.h"

using namespace std;

PriorityQueue::PriorityQueue() {
  size = 0;
}

void PriorityQueue::enqueue(int value, int priority) {
  size++;
  elements[size].value = value;
  elements[size].priority = priority;
}

int PriorityQueue::peek() {
  const int index = indexElementWithHighestPriority();
  return elements[index].value;
}

void PriorityQueue::dequeue() {
  const int index = indexElementWithHighestPriority();
  for (int i = index; i < size; i++) {
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
  int highestPriority = -999999;
  int index = -1;
  for (int i = 0; i <= size; i++) {
    if (highestPriority == elements[i].priority && index > -1 && elements[index].value < elements[i].value) {
      highestPriority = elements[i].priority;
      index = i;
    } else if (highestPriority < elements[i].priority) {
      highestPriority = elements[i].priority;
      index = i;
    }
  }
  return index;
}
