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

class PrivateDerived : private Base {
 public:
  int getProtected() {
    return protected_;
  }
  int getPublic() {
    return public_;
  }
};

int main() {
  PrivateDerived object;
  cout << "Private cannot be accessed." << endl;
  cout << "Protected = " << object.getProtected() << endl;
  cout << "Public = " << object.getPublic() << endl;
  return 0;
}