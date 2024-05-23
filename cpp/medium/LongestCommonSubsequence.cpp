#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
  vector<vector<int>> dp(text1.size() + 1, vector(text2.size() + 1, 0));
  int rs = 0;
  for (int i = 1; i <= text1.size(); ++i) {
    for (int k = 1; k <= text2.size(); ++k) {
      if (text1[i - 1] == text2[k - 1]) {
        dp[i][k] = dp[i - 1][k - 1] + 1;
      } else {
        dp[i][k] = max(dp[i - 1][k], dp[i][k - 1]);
      }
      if (dp[i][k] > rs) {
        rs = dp[i][k];
      }
    }
  }
  return rs;
}
