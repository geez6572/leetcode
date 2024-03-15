#include <algorithm>
#include <vector>
using namespace std;
int minCostClimbingStairs1(vector<int> &cost) {
  int size = cost.size();
  if (size <= 2)
    return cost[0] < cost[1] ? cost[0] : cost[1];
  int sum_cost = 0;
  vector<int> dp(size + 1);
  dp[0] = cost[0];
  dp[1] = cost[1];
  for (int i = 2; i < size; i++) {
    int path1 = cost[i] + dp[i - 1];
    int path2 = cost[i] + dp[i - 2];
    dp[i] = path1 < path2 ? path1 : path2;
  }
  return dp[size - 1] < dp[size - 2] ? dp[size - 1] : dp[size - 2];
}

int minCostClimbingStairs2(vector<int> &cost) {
  int size = cost.size();
  vector<int> dp(3);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= size; i++) {
    dp[2] = min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
    dp[0] = dp[1];
    dp[1] = dp[2];
  }
  return dp[1];
}
