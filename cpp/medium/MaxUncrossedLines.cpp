#include <algorithm>
#include <vector>
using namespace std;

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
  vector<vector<int>> dp(nums1.size() + 1, vector(nums2.size() + 1, 0));
  for (int i = 1; i <= nums1.size(); ++i) {
    for (int k = 1; k <= nums2.size(); ++k) {
      if (nums1[i - 1] == nums2[k - 1]) {
        dp[i][k] = dp[i - 1][k - 1];
      } else {
        dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]);
      }
    }
  }
  return dp.back().back();
}
