#include <iostream>

using namespace std;

class Base {
 private:
  int private_ = 1;
 protected:
  int protected_ = 2;
 public:
  int public_ = 3;
  int getPrivate() {
    return private_;
  }
};

class PublicDerived : public Base {
 public:
  int getProtected() {
    return protected_;
  }
};

int main() {
  PublicDerived object1;
  cout << "Private = " << object1.getPrivate() << endl;
  cout << "Protected = " << object1.getProtected() << endl;
  cout << "Public = " << object1.public_ << endl;
  return 0;
}
