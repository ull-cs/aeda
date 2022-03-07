#include <iostream>

using namespace std;

class DisjointSet {
 public:
  DisjointSet(int size);
  int find(int x);
  void Union(int x, int y);

 private:
  int *rank;
  int *parent;
  int size_;
};

DisjointSet::DisjointSet(int size) {
  rank = new int[size];
  parent = new int[size];
  this->size_ = size;
  for (int i = 0; i < size_; i++) {
    parent[i] = i;
  }
}

int DisjointSet::find(int toFind) {
  if (parent[toFind] != toFind) {
    parent[toFind] = find(parent[toFind]);
  }
  return parent[toFind];
}

// Do union of two sets represented by x and y.
void DisjointSet::Union(int x, int y) {
  // Find current sets of x and y
  int xset = find(x);
  int yset = find(y);
  // If they are already in same set
  if (xset == yset) {
    return;
  }
  // Put smaller ranked item under bigger ranked item if ranks are different
  if (rank[xset] < rank[yset]) {
    parent[xset] = yset;
  } else if (rank[xset] > rank[yset]) {
    parent[yset] = xset;
  }
  // If ranks are same, then increment rank.
  else {
    parent[yset] = xset;
    rank[xset] = rank[xset] + 1;
  }
}

int main(int argc, char *argv[]) {
  DisjointSet disjointSet(5);
  disjointSet.Union(0, 2);
  disjointSet.Union(4, 2);
  disjointSet.Union(3, 1);
  if (disjointSet.find(4) == disjointSet.find(0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  if (disjointSet.find(1) == disjointSet.find(0)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
