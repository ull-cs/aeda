#include <iostream>
#include <string>

using namespace std;

class Animal {
 public:
  Animal() : type("Animal") {}
  virtual string getType() {
    return type;
  }

 private:
  string type;
};

class Dog : public Animal {
 public:
  Dog() : type("Dog") {}
  string getType() override {
    return type;
  }

 private:
  string type;
};

class Cat : public Animal {
 public:
  Cat() : type("Cat") {}
  string getType() override {
    return type;
  }

 private:
  string type;
};

void print(Animal* animal) {
  cout << "Animal: " << animal->getType() << endl;
}

int main() {
  Animal* animal = new Animal();
  Animal* dog = new Dog();
  Animal* cat = new Cat();
  print(animal);
  print(dog);
  print(cat);
  return 0;
}
