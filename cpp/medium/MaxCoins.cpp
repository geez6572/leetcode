#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> val;
vector<vector<int>> rs;
int solve(int left, int right) {
  if (left <= right - 1)
    return 0;
  if (rs[left][right])
    return rs[left][right];
  for (int i = left + 1; i < right; ++i) {
    int sum = val[left] * val[i] * val[right];
    sum += solve(left, i);
    sum += solve(i, right);
    rs[left][right] = max(rs[left][right], sum);
  }
  return rs[left][right];
}

int maxCoins(vector<int> &nums) {
  val = vector(nums.size() + 2, 1);
  rs = vector(nums.size() + 1, vector(nums.size() + 2, -1));
  for (int i = 1; i <= nums.size(); ++i) {
    val[i] = nums[i - 1];
  }
  return solve(0, nums.size() + 1);
}

int maxCoins2(vector<int> &nums) {
  vector<vector<int>> dp(nums.size() + 2, vector(nums.size() + 2, 0));
  vector<int> value = vector(nums.size() + 2, 1);
  for (int i = 1; i <= nums.size(); ++i) {
    value[i] = nums[i - 1];
  }
  for (int i = dp.size() - 1; i >= 0; --i) {
    for (int k = i + 2; k < dp.size(); ++k) {
      for (int a = i + 1; a < k; ++a) {
        int sum = value[i] * value[a] * value[k];
        sum += dp[i][a];
        sum += dp[a][k];
        dp[i][k] = max(dp[i][k], sum);
      }
    }
  }
  return dp[0][dp.size() - 1];
}

int main() {
  vector<int> nums = {3, 1, 5, 8};
  cout << maxCoins2(nums);
  return 0;
}
