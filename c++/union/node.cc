#include <iostream>

struct Node {
  int id;
  struct Node* left;
  struct Node* right;
  union Type {
    int intValue;
    double doubleValue;
    char charValue;
  } value;
};

void PrintNode(const Node& node) {
  std::cout << "Node id=" << node.id << ", ";
  std::cout << "intType=" << node.value.intValue << ", ";
  std::cout << "doubleType=" << node.value.doubleValue << ", ";
  std::cout << "charValue=" << node.value.charValue;
  std::cout << std::endl;
}

int main() {
  Node root;
  root.id = 0;
  root.left = NULL;
  root.right = NULL;
  root.value.charValue = 'v';
  PrintNode(root);
  root.value.intValue = 270;
  PrintNode(root);
  return 0;
}
