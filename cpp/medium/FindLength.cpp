#include <algorithm>
#include <vector>
using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2) {
  vector<vector<int>> dp(nums1.size() + 1, vector(nums2.size() + 1, 0));
  int rs = 0;
  for (int i = 1; i <= nums1.size(); ++i) {
    for (int k = 1; k <= nums2.size(); ++k) {
      if (nums1[i - 1] == nums2[k - 1]) {
        dp[i][k] = dp[i - 1][k - 1] + 1;
      }
      if (dp[i][k] > rs) {
        rs = dp[i][k];
      }
    }
  }
  return rs;
}

// 滑动窗口
int maxPrefix(vector<int> nums1, vector<int> nums2, int index1, int index2) {
  int rs = 0;
  int cur = 0;
  while (index1 < nums1.size() && index2 < nums2.size()) {
    if (nums1[index1] == nums2[index2]) {
      cur++;
    } else {
      rs = max(rs, cur);
      cur = 0;
    }
    index1++;
    index2++;
  }
  return max(rs, cur);
}
int findLength2(vector<int> &nums1, vector<int> &nums2) {
  int rs = 0;
  for (int i = nums1.size() - 1; i >= 0; --i) {
    rs = max(rs, maxPrefix(nums1, nums2, i, 0));
  }
  for (int i = 0; i < nums2.size(); ++i) {
    rs = max(rs, maxPrefix(nums1, nums2, 0, i));
  }
  return rs;
}
