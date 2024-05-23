#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(int k, vector<int> &prices) {
  vector<vector<int>> dp(prices.size(), vector(k * 2 + 1, 0));
  for (int i = 1; i < k * 2 + 1; i += 2) {
    dp[0][i] = -prices[0];
  }

  for (int i = 1; i < prices.size(); ++i) {
    for (int j = 1; j < k * 2 + 1; ++j) {
      if (j % 2) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
      }
    }
    int b = 0;
  }
  return dp.back().back();
}

int main() {
  vector<int> prices = {2, 4, 1};
  cout << maxProfit(2, prices);
  return 0;
}
