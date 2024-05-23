#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
  for (int i = 0; i < matrix.size(); ++i) {
    for (int k = 0; k < i; ++k) {
      int temp = matrix[i][k];
      matrix[i][k] = matrix[k][i];
      matrix[k][i] = temp;
    }
  }
  for (int i = 0; i < matrix.size(); ++i) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotate(matrix);
  for (auto vec : matrix) {
    for (auto i : vec) {
      cout << i << ",";
    }
    cout << endl;
  }
  return 0;
}
