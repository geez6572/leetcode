#include <vector>
using namespace std;
int uniquePaths(int m, int n) {
  // 定义dp数组
  // dp数组中每一格表示到达当前格子有多少路径
  vector<vector<int>> dp(m, vector<int>(n, 0));
  // 初始化dp
  for (int i = 0; i < n; i++) {
    dp[0][i] = 1;
  }
  for (int i = 0; i < m; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i < m; i++) {
    for (int k = 1; k < n; k++) {
      dp[i][k] = dp[i - 1][k] + dp[i][k - 1];
    }
  }
  return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  int row = obstacleGrid.size();
  int col = obstacleGrid[0].size();
  vector<vector<int>> dp(row, vector<int>(col, 0));

  // 初始化dp
  for (int i = 0; i < col && !obstacleGrid[0][i]; i++) {
    dp[0][i] = 1;
  }
  for (int i = 0; i < row && !obstacleGrid[i][0]; i++) {
    dp[i][0] = 1;
  }

  for (int i = 1; i < row; i++) {
    for (int k = 1; k < col; k++) {
      if (!obstacleGrid[i][k])
        dp[i][k] = dp[i - 1][k] + dp[i][k - 1];
    }
  }
  return dp[row - 1][col - 1];
}
