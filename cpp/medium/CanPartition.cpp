// 416. 分割等和子集

#include <algorithm>
#include <vector>
using namespace std;

bool canPartition(vector<int> &nums) {
  if (nums.size() <= 1)
    return false;
  int count = 0;
  for (int num : nums) {
    count += num;
  }
  // 如果总和为奇数则必然不可能拆分为两个相等的子集
  if (count % 2)
    return false;
  count = count / 2;
  vector<vector<int>> dp(nums.size(), vector<int>(count + 1, 0));
  // 初始化
  for (int i = 0; i < nums.size(); i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= count; i++) {
    if (i >= nums[0])
      dp[0][i] = nums[0];
  }
  for (int i = 1; i < nums.size(); i++) {
    for (int k = 1; k <= count; k++) {
      if (nums[i] > k)
        dp[i][k] = dp[i - 1][k];
      else
        dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - nums[i]] + nums[i]);
    }
  }
  for (int i = 0; i < nums.size(); i++) {
    if (dp[i][count] == count)
      return true;
  }
  return false;
}

bool canPartition2(vector<int> &nums) {
  if (nums.size() <= 1) {
    return false;
  }
  int sum = 0;
  for (int i = 0; i < nums.size(); i++)
    sum += nums[i];
  if (sum % 2)
    return false;
  int target = sum / 2;
  vector<int> dp(target + 1, 0);

  for (int i = 0; i < nums.size(); i++) {
    for (int k = target; k >= nums[i]; k--) {
      dp[k] = max(dp[k], dp[k - nums[i]] + nums[i]);
    }
  }
  if (dp[target] == target)
    return true;
  return false;
}

int main() { vector<int> nums = {1, 2, 5}; }
