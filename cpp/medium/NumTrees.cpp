#include <vector>
using namespace std;

int numTrees(int n) {
  if (n <= 2)
    return n;
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    for (int k = 1; k <= i; k++) {
      dp[i] += dp[k - 1] * dp[i - k];
    }
  }
  return dp[n];
}
