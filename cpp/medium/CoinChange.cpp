#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int coinChange(vector<int> &coins, int amount) {
  if (amount == 0) {
    return 0;
  }
  vector<int> dp(amount + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= amount; ++i) {
    for (auto coin : coins) {
      if (coin > i)
        break;
      if (dp[i - coin] != INT_MAX) {
        dp[i] = min(dp[i - coin], dp[i]) + 1;
      }
    }
  }
  return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
  vector<int> coins = {1, 2, 5};
  coinChange(coins, 11);
  return 0;
}
