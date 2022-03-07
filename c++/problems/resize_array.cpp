#include <iostream>
#include <iterator>

using namespace std;

/*int* AddValueToVector(int* array, int valueToAdd) {

  int * array_tmp = new int[2 * array_size];
  // 3. copy over the old values
  for (int i = 0; i < array_size; i++) {
    array_tmp[i] = array[i];
  }
  // 4. delete the old array
  delete [] array;
  array = 0;
  // 5. assign the temporary pointer to the original
  array = array_tmp;
  // 6. set the temporary pointer to 0
  array_tmp = 0;
  // 7. update the size of the array
  array_size *= 2;
}*/

int main() {
  int array_size = 40;
  int* array = new int[array_size];
  for (int i = 0; i < array_size; i++) {
    array[i] = i * i;
  }
  // int array[] = { 1, 2, 3 };
  std::cout << sizeof(*array) << std::endl;
  std::cout << sizeof(array[0]) << std::endl;
  std::cout << sizeof(*array) / sizeof(int);
  // int arrSize = std::size(array);
  // cout << arrSize << endl;
  return 0;
  /*******************************************
   * Start Resizing the Array                *
   *******************************************/
  /*// 1. we require a temporary pointer
  int * array_tmp = 0;
  // 2. allocate twice as much memory
  array_tmp = new int[2 * array_size];
  // 3. copy over the old values
  for (int i = 0; i < array_size; i++) {
    array_tmp[i] = array[i];
  }
  // 4. delete the old array
  delete [] array;
  array = 0;
  // 5. assign the temporary pointer to the original
  array = array_tmp;
  // 6. set the temporary pointer to 0
  array_tmp = 0;
  // 7. update the size of the array
  array_size *= 2;*/
  /*******************************************
   * Finish Resizing the Array               *
   *******************************************/
  // continue using the new array...
  /*for ( int i = array_size/2; i < array_size; ++i ) {
    array[i] = i*i;
  }
  cout << "The squares are:";
  for (int i = 0; i < array_size; i++) {
    cout << " " << array[i];
  }
  cout << endl;
  // clean up...
  delete [] array;*/
  return 0;
}