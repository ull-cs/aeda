#ifndef NODE
#define NODE

template <typename T>
class Node {
 public:
  Node() {
    this->next = NULL;
  }

 private:
  T data;
  Node<T>* next;
  template <typename U>
  friend class LinkedList;
};

#endif
