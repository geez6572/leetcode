#include <algorithm>
#include <vector>

using namespace std;

int integerBreak(int n) {
  vector<int> dp(n + 1, 0);
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 1;
  for (int i = 3; i <= n; ++i) {
    int max = -1;
    for (int k = 1; k < i; k++) {
      int temp = std::max(k * (i - k), k * dp[i - k]);
      if (temp > max)
        max = temp;
    }
    dp[i] = max;
  }
  return dp[n];
}
