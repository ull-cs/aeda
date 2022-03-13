#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

int row[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int column[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isSafe(vector<vector<char>> const &matrix, int x, int y, char target) {
  return (x >= 0 && x < matrix.size()) && (y >= 0 && y < matrix[0].size()) && matrix[x][y] == target;
}

void FloodFill(vector<vector<char>> &matrix, int x, int y, char replacement) {
  if (matrix.size() == 0) {
    return;
  }
  queue<pair<int, int>> queue;
  queue.push({x, y});
  char target = matrix[x][y];
  if (target == replacement) {
    return;
  }
  while (!queue.empty()) {
    pair<int, int> node = queue.front();
    queue.pop();
    int x = node.first;
    int y = node.second;
    matrix[x][y] = replacement;
    for (int k = 0; k < 8; k++) {
      if (isSafe(matrix, x + row[k], y + column[k], target)) {
        queue.push({x + row[k], y + column[k]});
      }
    }
  }
}

void PrintMatrix(vector<vector<char>> const &matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << setw(3) << matrix[i][j];
    }
    cout << endl;
  }
}

int main() {
  vector<vector<char>> matrix = {
      {'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G'},
      {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'X', 'X', 'X'},
      {'G', 'G', 'G', 'G', 'G', 'G', 'G', 'X', 'X', 'X'},
      {'W', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'X'},
      {'W', 'R', 'R', 'R', 'R', 'R', 'G', 'X', 'X', 'X'},
      {'W', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'X'},
      {'W', 'B', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'X'},
      {'W', 'B', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X'},
      {'W', 'B', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X'},
      {'W', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}};
  int x = 3;
  int y = 9;
  char replacement = 'C';
  FloodFill(matrix, x, y, replacement);
  PrintMatrix(matrix);
  return 0;
}
