#include <string>
#include <vector>

using namespace std;

int findMaxForm(vector<string> &strs, int m, int n) {
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  // 遍历字符串数组(物品)
  for (string str : strs) {
    // 确定0和1的个数(重量)
    int zero = 0;
    int one = 0;
    for (char c : str) {
      if (c == '0')
        ++zero;
      else
        ++one;
    }
    // 根据0和1的个数(重量)遍历
    for (int i = m; i >= zero; --i) {
      for (int k = n; k >= one; --k) {
        dp[i][k] = max(dp[i][k], dp[i - zero][k - one] + 1);
      }
    }
  }
  return dp[m][n];
}
