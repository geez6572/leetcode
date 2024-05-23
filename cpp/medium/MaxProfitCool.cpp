#include <algorithm>
#include <vector>
using namespace std;
int maxProfit(vector<int> &prices) {
  vector<vector<int>> dp(prices.size(), vector(3, 0));
  dp[0][0] = -prices[0];
  for (int i = 1; i < prices.size(); ++i) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
    dp[i][1] = dp[i - 1][0] + prices[i];
    dp[i][2] = dp[i - 1][1];
  }
  return max(dp.back()[1], dp.back()[2]);
}
