#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>> &matrix) {
  vector<vector<int>> dp(matrix.size() + 1, vector(matrix[0].size() + 1, 0));
  int rs = 0;
  for (int i = 1; i < dp.size(); ++i) {
    for (int k = 1; k < dp[0].size(); ++k) {
      if (matrix[i - 1][k - 1] == '1') {
        dp[i][k] = min(dp[i - 1][k - 1], min(dp[i - 1][k], dp[i][k - 1]));
        rs = max(dp[i][k], rs);
      }
    }
  }
  return rs;
}

int main() {

  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};
  cout << maximalSquare(matrix);
  return 0;
}
