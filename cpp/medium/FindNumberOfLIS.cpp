#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

int findNumberOfLIS(vector<int> &nums) {
  vector<pair<int, int>> dp(nums.size(), make_pair(1, 1));
  pair<int, int> rs(1, 1);
  for (int i = 1; i < nums.size(); ++i) {
    for (int k = 0; k < i; ++k) {
      if (nums[k] < nums[i]) {
        if (dp[i].first < dp[k].first + 1) {
          dp[i].first = dp[k].first + 1;
          dp[i].second = dp[k].second;
        } else if (dp[i].first == dp[k].first + 1) {
          dp[i].second += dp[k].second;
        }
      }
    }
    if (dp[i].first > rs.first) {
      rs = dp[i];
    } else if (dp[i].first == rs.first) {
      rs.second += dp[i].second;
    }
  }
  return rs.second;
}

int main() {
  vector<int> nums = {2, 2, 2, 2, 2};
  cout << findNumberOfLIS(nums);
  return 0;
}
