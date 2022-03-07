#ifndef NODE
#define NODE

template <typename T>
class Node {
 public:
  Node() {
    this->next = NULL;
  }
  Node(T data) {
    this->data = data;
    this->next = NULL;
  }

 private:
  T data;
  Node<T>* next;
  template <typename U>
  friend class AssociationList;
};

#endif
