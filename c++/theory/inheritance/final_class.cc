#include <iostream>

using namespace std;

class Unique final {
 public:
  void display() {
    cout << "My unique class" << endl;
  }
};

// class Derived : Unique {
// YOUR GET ERROR HERE if you inherit the Unique class
// class Unique - a final class cannot be used as
// a base class.
//};

int main() {
  Unique object;
  object.display();
  return 0;
}
