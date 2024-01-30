#include <iostream>

using namespace std;

class ClassB;

class ClassA {
 public:
  ClassA() : numA_(12) {}

 private:
  int numA_;
  friend int AddNumbers(ClassA, ClassB);
};

class ClassB {
 public:
  ClassB() : numB_(1) {}

 private:
  int numB_;
  friend int AddNumbers(ClassA, ClassB);
};

int AddNumbers(ClassA objectA, ClassB objectB) {
  return (objectA.numA_ + objectB.numB_);
}

int main() {
  ClassA objectA;
  ClassB objectB;
  cout << "Sum: " << AddNumbers(objectA, objectB) << endl;
  return 0;
}
