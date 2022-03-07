#include <iostream>

using namespace std;

class Animal {
 public:
  void eat() {
    cout << "I can eat!" << endl;
  }
  void sleep() {
    cout << "I can sleep!" << endl;
  }
};

class Dog : public Animal {
 public:
  void bark() {
    cout << "I can bark! Woof woof!!" << endl;
  }
};

int main() {
  Dog dog1;
  dog1.eat();
  dog1.sleep();
  dog1.bark();
  return 0;
}
