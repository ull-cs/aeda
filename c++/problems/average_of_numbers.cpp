#include <iostream>

using namespace std;

int main() {
  int numberOfElements;
  cout << "Enter the number of items: ";
  cin >> numberOfElements;
  int *numbers = new int[numberOfElements];
  cout << "Enter " << numberOfElements << " items:" << endl;
  for (int i = 0; i < numberOfElements; i++) {
    cin >> numbers[i];
  }
  double average = 0.0;
  cout << "You entered: ";
  for (int i = 0; i < numberOfElements; i++) {
    average += numbers[i];
    cout << numbers[i] << " ";
  }
  average /= numberOfElements;
  cout << endl;
  cout << "Average: " << average << endl;
  delete[] numbers;
  return 0;
}