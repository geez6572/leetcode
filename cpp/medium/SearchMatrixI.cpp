#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int row = matrix.size();
  int col = matrix[0].size();
  int start_index = 0;
  int end_index = row * col - 1;
  while (start_index <= end_index) {
    int mid = (end_index - start_index) / 2;
    int mid_x = mid / col;
    int mid_y = mid % col;
    if (matrix[mid_x][mid_y] > target) {
      end_index = mid - 1;
    } else if (matrix[mid_x][mid_y] < target) {
      start_index = mid + 1;
    } else {
      return true;
    }
  }
  return false;
}

int main() {
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  cout << searchMatrix(matrix, 3);
  return 0;
}
