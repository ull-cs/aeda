#ifndef PAIR
#define PAIR

template <class T>
class Pair {
 public:
  Pair() {}
  Pair(T first, T second) {
    element1_ = first;
    element2_ = second;
  }
  T GetMax();
  template <class U>
  friend std::ostream& operator<<(std::ostream& out, const Pair<U>& pair);

 private:
  T element1_;
  T element2_;
};

template <class T>
std::ostream& operator<<(std::ostream& out, const Pair<T>& pair) {
  out << "{" << pair.element1_ << "," << pair.element2_ << "}";
  return out;
}

#endif
