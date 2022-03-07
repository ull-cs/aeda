#include <iostream>

using namespace std;

template <class T>
class Box {
 public:
  Box(T data) {
    data_ = data;
  }
  void Print() {
    cout << data_ << endl;
  }

 private:
  T data_;
};

template <>
class Box<bool> {
 public:
  Box(bool data) {
    data_ = data;
  }
  void Print() {
    cout << (data_ ? "true" : "false") << endl;
  }

 private:
  bool data_;
};

int main() {
  Box<int> intBox(27);
  Box<bool> boolBox(true);
  cout << "intBox: ";
  intBox.Print();
  cout << "boolBox: ";
  boolBox.Print();
  return 0;
}
