#include <algorithm>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices) {
  vector<vector<int>> dp(prices.size(), vector(5, 0));
  dp[0][1] = -prices[0];
  dp[0][3] = -prices[0];
  for (int k = 1; k < prices.size(); ++k) {
    dp[k][0] = dp[k - 1][0];
    dp[k][1] = max(dp[k - 1][1], dp[k - 1][0] - prices[k]);
    dp[k][2] = max(dp[k - 1][2], dp[k - 1][1] + prices[k]);
    dp[k][3] = max(dp[k - 1][3], dp[k - 1][2] - prices[k]);
    dp[k][4] = max(dp[k - 1][4], dp[k - 1][3] + prices[k]);
  }
  return dp.back().back();
}
