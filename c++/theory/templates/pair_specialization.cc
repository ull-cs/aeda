#include <iostream>
#include <string>

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

template <>
class Pair<char> {
 public:
  Pair(char first, char second) {
    element1_ = first;
    element2_ = second;
  }
  string ToString() {
    string result = "{";
    result.push_back(element1_);
    result.push_back(',');
    result.push_back(element2_);
    result.push_back('}');
    return result;
  }

 private:
  char element1_;
  char element2_;
};

int main() {
  Pair<int> myPair(100, 75);
  cout << "Maximum: " << myPair.GetMax() << endl;
  Pair<char> charPair('a', 'b');
  // cout << "Char pair: " << charPair.GetMax() << endl; // compilation error
  cout << "Char pair: " << charPair.ToString() << endl;
  return 0;
}
