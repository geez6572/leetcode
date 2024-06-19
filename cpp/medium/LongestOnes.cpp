#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int longestOnes(vector<int> &nums, int k) {
  int used = 0;
  int left = 0;
  int rs = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] == 0) {
      if (used < k) {
        used++;
        rs = max(rs, i - left + 1);
      } else if (used > 0) {
        while (nums[left] == 1) {
          left++;
        }
        left++;
      } else {
        left = i;
      }
    } else {
      if (k == 0 && nums[left] == 0)
        left = i;
      rs = max(rs, i - left + 1);
    }
  }
  return rs;
}

int longestOnes2(vector<int> &nums, int k) {
  vector<vector<int>> dp(2, vector(nums.size() + 1, 0));
  for (int i = 1; i <= nums.size(); ++i) {
    if (nums[i - 1] == 1)
      dp[0][i] = dp[0][i - 1] + 1;
  }
  int pre = 0;
  int cur = 1;
  for (int i = 1; i <= k; ++i) {
    for (int k = 1; k <= nums.size(); ++k) {
      if (nums[k - 1] == 0) {
        dp[cur][k] = dp[pre][k - 1] + 1;
      } else {
        dp[cur][k] = dp[cur][k - 1] + 1;
      }
    }
    swap(pre, cur);
  }
  int rs = 0;
  for (auto i : dp[pre]) {
    rs = max(i, rs);
  }
  return rs;
}
