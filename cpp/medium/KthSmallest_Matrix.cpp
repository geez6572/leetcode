#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int check(vector<vector<int>> &matrix, int mid) {
  int x = matrix.size() - 1;
  int y = 0;
  int count = 0;
  while (x >= 0 && y < matrix.size()) {
    if (matrix[x][y] > mid) {
      x--;
    } else {
      count += x + 1;
      y++;
    }
  }
  return count;
}

int kthSmallest(vector<vector<int>> &matrix, int k) {
  int n = matrix.size();
  int left = matrix[0][0];
  int right = matrix[n - 1][n - 1];
  while (left < right) {
    int mid = left + ((right - left) >> 1);
    int count = check(matrix, mid);
    if (count > k) {
      right = mid - 1;
    } else if (count < k) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return left;
}

int main() {
  vector<vector<int>> matrix = {{1, 2}, {1, 3}};
  cout << kthSmallest(matrix, 4);
  return 0;
}
