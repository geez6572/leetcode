#include <algorithm>
#include <vector>
using namespace std;

// 贪心
int maxSubArray(vector<int> &nums) {
  int rs = nums[0];
  int cur = 0;
  for (int i = 0; i < nums.size(); ++i) {
    cur += nums[i];
    rs = max(cur, rs);
    if (cur < 0) {
      cur = 0;
    }
  }
  return rs;
}

// 动态规划
int maxSubArray2(vector<int> &nums) {
  vector<int> dp(nums.size(), 0);
  dp[0] = nums[0];
  int rs = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    dp[i] = max(dp[i - 1], nums[i]);
    rs = max(rs, dp[i]);
  }
  return rs;
}
