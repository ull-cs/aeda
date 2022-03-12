#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

int main() {
  FILE *filePointer = fopen("nonexistingfile.txt", "r");
  if (filePointer == NULL) {
    cerr << "Failed to open the file" << endl;
    abort();
  }
  // Normal processing continues here
  fclose(filePointer);
  cout << "Normal return" << endl;
  return 0;
}
