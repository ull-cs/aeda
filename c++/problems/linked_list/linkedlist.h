#include "node.h"

#ifndef LINKEDLIST
#define LINKEDLIST

using namespace std;

template <typename T>
class LinkedList {
 public:
  LinkedList();
  void add(T item);
  void addFront(T item);
  void add(int index, T item);
  int length();
  void displayAll();
  void remove();
  void remove(int index);
  void removeFront();
  T get(int index);

 private:
  Node<T> *head;
};

template <typename T>
LinkedList<T>::LinkedList() {
  this->head = NULL;
}

template <typename T>
void LinkedList<T>::add(T item) {
  Node<T> *node = new Node<T>[1];
  node->data = item;
  if (head == NULL) {
    head = node;
    cout << "New node added (firstnode)" << endl;
    return;
  }
  Node<T> *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
  cout << "New node added at back" << endl;
}

template <typename T>
void LinkedList<T>::addFront(T item) {
  Node<T> *node = new Node<T>[1];
  node->data = item;
  if (head == NULL) {
    head = node;
    cout << "New node added (firstnode) !" << endl;
    return;
  }
  node->next = head;
  head = node;
  cout << "New node added at front !" << endl;
}

template <typename T>
void LinkedList<T>::add(int index, T item) {
  if (index > length() || index < 0) {
    cout << "Index out of bound !" << endl;
    return;
  }
  Node<T> *node = new Node<T>[1];
  node->data = item;
  int count = 0;
  Node<T> *temp = head;
  while (temp != NULL && count < index) {
    if (count == index - 1) {
      if (temp->next != NULL) {
        node->next = temp->next;
      }
      temp->next = node;
      cout << "New node added at index " << index << " !" << endl;
      break;
    }
    count++;
    temp = temp->next;
  }
}

template <typename T>
int LinkedList<T>::length() {
  int len = 0;
  Node<int> *temp = head;
  while (temp != NULL) {
    len++;
    temp = temp->next;
  }
  return len;
}

template <typename T>
void LinkedList<T>::displayAll() {
  if (head == NULL) {
    cout << "Linked list is empty" << endl;
    return;
  }
  cout << endl
       << "----Link list items------" << endl;
  Node<T> *temp = head;
  while (temp != NULL) {
    cout << temp->data << " | ";
    temp = temp->next;
  }
  cout << endl
       << "--------------------------" << endl;
}

template <typename T>
void LinkedList<T>::remove() {
  if (head == NULL) {
    cout << "Linked list is empty !" << endl;
    return;
  }
  if (head->next == NULL) {
    head = NULL;
    cout << "Last item removed" << endl;
    return;
  }

  Node<T> *temp = head;
  while (temp != NULL) {
    if (temp->next->next == NULL) {
      temp->next = NULL;
      cout << "Last item removed" << endl;
      break;
    }
    temp = temp->next;
  }
}

template <class T>
void LinkedList<T>::remove(int index) {
  if (head == NULL) {
    cout << "Linked list is empty !" << endl;
    return;
  }
  if (index >= length() || index < 0) {
    cout << "Index out of bound !" << endl;
    return;
  }
  if (index == 0) {
    removeFront();
    cout << "Item removed at index " << index << endl;
    return;
  }

  int count = 0;
  Node<T> *temp = head;
  while (temp != NULL) {
    if (count == index - 1) {
      temp->next = temp->next->next;
      cout << "Item removed at index " << index << endl;
      break;
    }
    count++;
    temp = temp->next;
  }
}

template <class T>
void LinkedList<T>::removeFront() {
  if (head == NULL) {
    cout << "Linked list is empty !" << endl;
    return;
  }
  head = head->next;
  cout << "Front item removed" << endl;
}

template <class T>
T LinkedList<T>::get(int index) {
  if (head == NULL) {
    cout << "Linked list is empty !" << endl;
    return -9999;
  }
  if (index >= length() || index < 0) {
    cout << "Index out of bound !" << endl;
    return -9999;
  }
  if (index == 0) {
    return head->data;
  }
  int count = 0;
  T res;
  Node<T> *temp = head;
  while (temp != NULL) {
    if (count++ == index) {
      res = temp->data;
      break;
    }
    temp = temp->next;
  }
  return res;
}

#endif
