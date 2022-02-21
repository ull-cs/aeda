#include "deque.h"

Deque::Deque(int size) {
  front = -1;
  rear = 0;
  this->size = size;
}

bool Deque::isFull() {
  return ((front == 0 && rear == size - 1) || front == rear + 1);
}

bool Deque::isEmpty() {
  return (front == -1);
}

void Deque::insertFront(int key) {
  if (isFull()) {
    return;
  }
  if (front == -1) {
    front = 0;
    rear = 0;
  } else if (front == 0) {
    front = size - 1;
  } else {
    front = front - 1;
  }
  elements[front] = key;
}

void Deque ::insertRear(int key) {
  if (isFull()) {
    return;
  }
  if (front == -1) {
    front = 0;
    rear = 0;
  } else if (rear == size - 1) {
    rear = 0;
  } else {
    rear = rear + 1;
  }
  elements[rear] = key;
}

void Deque ::deleteFront() {
  if (isEmpty()) {
    return;
  }
  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (front == size - 1) {
    front = 0;
  } else {
    front = front + 1;
  }
}

void Deque::deleteRear() {
  if (isEmpty()) {
    return;
  }
  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (rear == 0) {
    rear = size - 1;
  } else {
    rear = rear - 1;
  }
}

int Deque::getFront() {
  if (isEmpty()) {
    return -1;
  }
  return elements[front];
}

int Deque::getRear() {
  if (isEmpty() || rear < 0) {
    return -1;
  }
  return elements[rear];
}
