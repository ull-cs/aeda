#include <iostream>

using namespace std;

class ClassB;

class ClassA {
 public:
  ClassA() : numA_(12) {}

 private:
  int numA_;
  friend class ClassB;
};

class ClassB {
 public:
  ClassB() : numB_(1) {}
  int AddNumbers(ClassA objectA) {
    return (objectA.numA_ + numB_);
  }

 private:
  int numB_;
};

int main() {
  ClassA objectA;
  ClassB objectB;
  cout << "Sum: " << objectB.AddNumbers(objectA) << endl;
  return 0;
}
