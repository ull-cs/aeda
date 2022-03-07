#include <iostream>

using namespace std;

template <typename T>
class Array {
 public:
  Array(T[], int);
  void Print();

 private:
  T *data_;
  int size_;
};

template <typename T>
Array<T>::Array(T data[], int size) {
  data_ = new T[size];
  size_ = size;
  for (int i = 0; i < size_; i++) {
    data_[i] = data[i];
  }
}

template <typename T>
void Array<T>::Print() {
  for (int i = 0; i < size_; i++) {
    cout << " " << *(data_ + i);
  }
  cout << endl;
}

int main() {
  int data[5] = {1, 2, 3, 4, 5};
  Array<int> array(data, 5);
  array.Print();
  return 0;
}
