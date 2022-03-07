#include <iostream>
#include <string>

using namespace std;

class Animal {
 public:
  void eat() {
    cout << "I can eat!" << endl;
  }
  void sleep() {
    cout << "I can sleep!" << endl;
  }
  void setColor(string clr) {
    color = clr;
  }
  string getColor() {
    return color;
  }

 protected:
  string type;

 private:
  string color;
};

class Dog : public Animal {
 public:
  void setType(string tp) {
    type = tp;
  }
  void displayInfo(string c) {
    cout << "I am a " << type << endl;
    cout << "My color is " << c << endl;
  }
  void bark() {
    cout << "I can bark! Woof woof!!" << endl;
  }
};

int main() {
  Dog dog1;
  dog1.eat();
  dog1.sleep();
  dog1.setColor("black");
  dog1.bark();
  dog1.setType("mammal");
  dog1.displayInfo(dog1.getColor());
  return 0;
}
