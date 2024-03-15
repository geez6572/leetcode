#include <algorithm>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
  int row_size = matrix.size();
  int col_size = matrix[0].size();
  vector<int> rs(row_size * col_size, 0);
  int rs_index = 0;
  int freq = min(row_size, col_size) / 2;
  for (int i = 0; i < freq; ++i) {
    int s_row = i;
    int s_col = i;
    while (s_col < row_size - 1 - i) {
      rs[rs_index++] = matrix[s_row][s_col++];
    }
    while (s_row < col_size - 1 - i) {
      rs[rs_index++] = matrix[s_row++][s_col];
    }
    while (s_col > i) {
      rs[rs_index++] = matrix[s_row][s_col--];
    }
    while (s_row > i) {
      rs[rs_index++] = matrix[s_row--][s_col];
    }
  }
  if (rs_index < rs.size()) {
    int col = freq;
    int row = freq;
    if (row_size == col_size)
      rs[rs_index] = matrix[row][col];
    else if (row_size > col_size) {
      while (rs_index < rs.size()) {
        rs[rs_index++] = matrix[row++][col];
      }
    } else {
      while (rs_index < rs.size()) {
        rs[rs_index++] = matrix[row][col++];
      }
    }
  }
  return rs;
}
