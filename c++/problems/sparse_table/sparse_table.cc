#include <bits/stdc++.h>

#include <iostream>

using namespace std;

#define MAX 500

// lookup[i][j] is going to store minimum value in arr[i..j]. 
// Ideally lookup table size should not be fixed and should be determined using n Log n. 
// It is kept constant to keep code simple.
int lookup[MAX][MAX];

// Fills lookup array lookup[][] in bottom up manner.
void buildSparseTable(int arr[], int n) {
  // Initialize M for the intervals with length 1
  for (int i = 0; i < n; i++) {
    lookup[i][0] = arr[i];
  }
  // Compute values from smaller to bigger intervals
  for (int j = 1; (1 << j) <= n; j++) {
    // Compute minimum value for all intervals with size 2^j
    for (int i = 0; (i + (1 << j) - 1) < n; i++) {
      // For arr[2][10], we compare arr[lookup[0][7]] and arr[lookup[3][10]]
      if (lookup[i][j - 1] < lookup[i + (1 << (j - 1))][j - 1]) {
        lookup[i][j] = lookup[i][j - 1];
      } else {
        lookup[i][j] = lookup[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}

// Returns minimum of arr[L..R]
int query(int L, int R) {
  // Find highest power of 2 that is smaller  than or equal to count of elements in given
  // range. For [2, 10], j = 3
  int j = (int)log2(R - L + 1);
  // Compute minimum of last 2^j elements with first 2^j elements in range.
  // For [2, 10], we compare arr[lookup[0][3]] and arr[lookup[3][3]],
  if (lookup[L][j] <= lookup[R - (1 << j) + 1][j]) {
    return lookup[L][j];
  } else {
    return lookup[R - (1 << j) + 1][j];
  }
}

int main() {
  int data[] = {7, 2, 3, 0, 5, 10, 3, 12, 18};
  int size = sizeof(data) / sizeof(data[0]);
  buildSparseTable(data, size);
  cout << "Minimum in [0..4]: " << query(0, 4) << endl;
  cout << "Minimum in [4..7]: " << query(4, 7) << endl;
  cout << "Minimum in [7..8]: " <<  query(7, 8) << endl;
  return 0;
}
