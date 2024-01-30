#include <iostream>

using namespace std;

class Unique {
 public:
  static Unique* GetInstance() {
    return new Unique();
  }
  void Display() {
    cout << "My Unique Class" << endl;
  }

 private:
  Unique() {}
};

int main() {
  Unique* u = Unique::GetInstance();
  u->Display();
  return 0;
}
