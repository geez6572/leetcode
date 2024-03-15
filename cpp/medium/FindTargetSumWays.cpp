#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int findTargetSumWays(vector<int> &nums, int target) {
  int sum = 0;
  for (int i = 0; i < nums.size(); i++)
    sum = sum + nums[i];
  int x = sum + target;
  if (x % 2 || abs(target) > sum)
    return 0;
  x = x / 2;
  vector<int> dp(x + 1, 0);
  for (int i = 0; i < nums.size(); i++) {
    for (int k = x; k >= nums[i]; k--) {
      dp[k] = dp[k] + dp[k - nums[i]];
    }
  }
  return dp[x];
}
