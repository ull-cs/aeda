#include <iostream>

using namespace std;

class Base {
 public:
  int public_ = 3;
  int getPrivate() {
    return private_;
  }

 protected:
  int protected_ = 2;

 private:
  int private_ = 1;
};

class PublicDerived : public Base {
 public:
  int getProtected() {
    return protected_;
  }
};

int main() {
  PublicDerived object;
  cout << "Private = " << object.getPrivate() << endl;
  cout << "Protected = " << object.getProtected() << endl;
  cout << "Public = " << object.public_ << endl;
  return 0;
}
