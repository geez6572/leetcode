#include <algorithm>
#include <vector>
using namespace std;

// dynamic plan
int maxProfit(vector<int> &prices, int fee) {
  vector<vector<int>> dp(prices.size(), vector(2, 0));
  dp[0][0] = -prices[0];
  for (int i = 1; i < prices.size(); ++i) {
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
  }
  return dp.back()[1];
}

// greedy stratgy

int maxProfit2(vector<int> &prices, int fee) {
  int minprice = prices[0];
  int rs = 0;
  for (int i = 1; i < prices.size(); ++i) {
    if (prices[i] < minprice) {
      minprice = prices[i];
    } else if (minprice + fee < prices[i]) {
      rs += prices[i] - minprice - fee;
      minprice = prices[i] - fee;
    }
  }
  return rs;
}
