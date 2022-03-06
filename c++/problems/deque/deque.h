#ifndef DEQUE
#define DEQUE

#include <iostream>

using namespace std;

#define MAX 1000

class Deque {
 public:
  Deque(int size);
  void insertFront(int key);
  void insertRear(int key);
  void deleteFront();
  void deleteRear();
  bool isFull();
  bool isEmpty();
  int getFront();
  int getRear();

 private:
  int elements[MAX];
  int front;
  int rear;
  int size;
};

#endif
