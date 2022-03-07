#include "node.h"

#ifndef ASSOCIATIONLIST
#define ASSOCIATIONLIST

using namespace std;

template <typename T>
class AssociationList {
 public:
  AssociationList();
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
AssociationList<T>::AssociationList() {
  this->head = NULL;
}

template <typename T>
void AssociationList<T>::add(T item) {
  Node<T> *node = new Node<T>[1];
  node->data = item;
  if (head == NULL) {
    head = node;
    return;
  }
  Node<T> *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
}

template <typename T>
void AssociationList<T>::addFront(T item) {
  Node<T> *node = new Node<T>[1];
  node->data = item;
  if (head == NULL) {
    head = node;
    return;
  }
  node->next = head;
  head = node;
}

template <typename T>
void AssociationList<T>::add(int index, T item) {
  if (index > length() || index < 0) {
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
      break;
    }
    count++;
    temp = temp->next;
  }
}

template <typename T>
int AssociationList<T>::length() {
  int len = 0;
  Node<int> *temp = head;
  while (temp != NULL) {
    len++;
    temp = temp->next;
  }
  return len;
}

template <typename T>
void AssociationList<T>::displayAll() {
  if (head == NULL) {
    cout << "List is empty" << endl;
    return;
  }
  cout << endl
       << "----List items------" << endl;
  Node<T> *temp = head;
  while (temp != NULL) {
    cout << temp->data << " | ";
    temp = temp->next;
  }
  cout << endl
       << "--------------------------" << endl;
}

template <typename T>
void AssociationList<T>::remove() {
  if (head == NULL) {
    return;
  }
  if (head->next == NULL) {
    head = NULL;
    return;
  }
  Node<T> *temp = head;
  while (temp != NULL) {
    if (temp->next->next == NULL) {
      temp->next = NULL;
      break;
    }
    temp = temp->next;
  }
}

template <class T>
void AssociationList<T>::remove(int index) {
  if (head == NULL) {
    return;
  }
  if (index >= length() || index < 0) {
    return;
  }
  if (index == 0) {
    removeFront();
    return;
  }
  int count = 0;
  Node<T> *temp = head;
  while (temp != NULL) {
    if (count == index - 1) {
      temp->next = temp->next->next;
      break;
    }
    count++;
    temp = temp->next;
  }
}

template <class T>
void AssociationList<T>::removeFront() {
  if (head == NULL) {
    return;
  }
  head = head->next;
}

template <class T>
T AssociationList<T>::get(int index) {
  if (head == NULL) {
    return -9999;
  }
  if (index >= length() || index < 0) {
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
