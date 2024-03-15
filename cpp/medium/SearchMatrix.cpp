#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int row = 0;
  int col = matrix[0].size() - 1;
  while (row < matrix.size() && col < matrix[0].size()) {
    if (matrix[row][col] > target) {
      col--;
    } else if (matrix[row][col] < target) {
      row++;
    } else {
      return true;
    }
  }
  return false;
}
