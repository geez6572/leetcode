#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int> &nums) {
  vector<vector<int>> dp(nums.size(), vector(2, 0));
  if (nums[0] > 0) {
    dp[0][0] = nums[0];
  } else if (nums[0] < 0) {
    dp[0][1] = nums[0];
  }
  int rs = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] > 0) {
      dp[i][0] = max(dp[i - 1][0] * nums[i], nums[i]);
      dp[i][1] = min(dp[i - 1][1] * nums[i], 0);
    } else if (nums[i] == 0) {
      dp[i][0] = 0;
      dp[i][1] = 0;
    } else {
      dp[i][0] = max(dp[i - 1][1] * nums[i], 0);
      dp[i][1] = min(dp[i - 1][0] * nums[i], nums[i]);
    }
    rs = max(dp[i][0], rs);
  }
  return rs;
}

int main() {
  vector<int> nums = {2, -5, -2, -4, 3};
  cout << maxProduct(nums);
  return 0;
}
