#include <iostream>

template <typename T, int size>
class StaticArray {
 public:
  T* GetData();
  T& operator[](int index) {
    return data_[index];
  }
  void Print() {
    for (int i{0}; i < size; i++) {
      std::cout << data_[i] << ' ';
    }
    std::cout << std::endl;
  }
 private:
  T data_[size] {};
};

template <typename T, int size>
T* StaticArray<T, size>::GetData() {
  return data_;
}

int main() {
  // int array
  const int kSizeIntArray = 12;
  StaticArray<int, kSizeIntArray> intArray;
  for (int i{0}; i < kSizeIntArray; i++) {
    intArray[i] = i;
  }
  intArray.Print();
  // double array
  const int kSizeDoubleArray = 4;
  StaticArray<double, kSizeDoubleArray> doubleArray;
  for (int i{0}; i < kSizeDoubleArray; i++) {
    doubleArray[i] = 4.4 + 0.1 * i;
  }
  doubleArray.Print();
  return 0;
}