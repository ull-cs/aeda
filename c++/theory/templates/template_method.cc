#include <iostream>

template <typename T, int size>
class StaticArray {
 public:
  T& operator[](int index);
  T* GetData();
  template <class U>
  void Print(U identifier) {
    std::cout << "Array " << identifier << ": ";
    for (int i{0}; i < size; i++) {
      std::cout << data_[i] << ' ';
    }
    std::cout << std::endl;
  }

 private:
  T data_[size];
};

template <typename T, int size>
T& StaticArray<T, size>::operator[](int index) {
  return data_[index];
}

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
  intArray.Print<int>(23);
  // double array
  const int kSizeDoubleArray = 4;
  StaticArray<double, kSizeDoubleArray> doubleArray;
  for (int i{0}; i < kSizeDoubleArray; i++) {
    doubleArray[i] = 4.4 + 0.1 * i;
  }
  doubleArray.Print("My array of doubles");
  return 0;
}