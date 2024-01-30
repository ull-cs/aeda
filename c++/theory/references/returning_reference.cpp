#include <ctime>
#include <iostream>

using namespace std;

double kPoints[] = {10.1, 12.6, 33.1, 24.1, 50.0};

double& GetPoints(int index) {
  return kPoints[index];
}

int main() {
  cout << "Value before change" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "kPoints[" << i << "] = ";
    cout << kPoints[i] << endl;
  }
  GetPoints(1) = 20.23;  // change 2nd element
  GetPoints(3) = 70.8;   // change 4th element
  cout << "Value after change" << endl;
  for (int i = 0; i < 5; i++) {
    cout << "kPoints[" << i << "] = ";
    cout << kPoints[i] << endl;
  }
  return 0;
}