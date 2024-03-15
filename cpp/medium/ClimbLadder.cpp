#include "vector"
#include <algorithm>
#include <vector>
using namespace std;

// 空间复杂度O(n)
int climbStairs1(int n) {
  if (n <= 2)
    return n;
  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[[i - 1] + dp[i - 2];
  }
  return dp[n + 1];
}

int climbStairs2(int n) {
  if (n <= 2)
    return n;
  vector<int> dp(3);
  dp[0] = 1;
  dp[1] = 2;
  int count = 3;
  while (count <= n) {
    dp[2] = dp[1] + dp[0];
    dp[0] = dp[1];
    dp[1] = dp[2];
    count++;
  }
  return dp[1];
}
