#include <algorithm>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid) {
  vector<vector<int>> dp(grid.size(), vector(grid[0].size(), 0));
  // initialize dp
  dp[0][0] = grid[0][0];
  for (int i = 1; i < dp.size(); ++i)
    dp[i][0] = dp[i - 1][0] + grid[i][0];
  for (int i = 1; i < dp[0].size(); ++i)
    dp[0][i] = dp[0][i - 1] + grid[0][i];

  // travel
  for (int i = 1; i < dp.size(); ++i) {
    for (int k = 1; k < dp[0].size(); ++k) {
      dp[i][k] = min(dp[i - 1][k], dp[i][k - 1]) + grid[i][k];
    }
  }
  return dp.back().back();
}
