#include <iostream>

using namespace std;

template <class T>
class Pair {
 public:
  Pair(T first, T second) {
    element1_ = first;
    element2_ = second;
  }
  T GetMax();

 private:
  T element1_;
  T element2_;
};

template <class T>
T Pair<T>::GetMax() {
  return (element1_ > element2_) ? element1_ : element2_;
}

int main() {
  Pair<int> myPair(100, 75);
  cout << "Maximum: " << myPair.GetMax() << endl;
  return 0;
}
