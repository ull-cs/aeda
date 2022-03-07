#include <cstdlib>
#include <iostream>

using namespace std;

class Array {
 public:
  Array(int*, int);
  int& operator[](int);
  void Print() const;

 private:
  int* ptr;
  int size;
};

Array::Array(int* p = NULL, int size = 0) {
  this->size = size;
  ptr = NULL;
  if (size != 0) {
    ptr = new int[size];
    for (int i = 0; i < size; i++) {
      ptr[i] = p[i];
    }
  }
}

int& Array::operator[](int index) {
  if (index >= size) {
    cout << "Array index out of bound, exiting";
    exit(0);
  }
  return ptr[index];
}

void Array::Print() const {
  for (int i = 0; i < size; i++) {
    cout << ptr[i] << " ";
  }
  cout << endl;
}

int main() {
  int data[] = {1, 2, 4, 5};
  Array array(data, 4);
  array[2] = 6;
  array.Print();
  array[8] = 6;
  return 0;
}
