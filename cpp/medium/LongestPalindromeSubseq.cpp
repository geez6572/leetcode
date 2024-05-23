#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestPalindromeSubseq(string s) {
  vector<vector<int>> dp(s.size(), vector(s.size(), 0));
  for (int i = 0; i < s.size(); ++i) {
    for (int k = i; k >= 0; --k) {
      if (s[i] == s[k]) {
        if (i - k > 1) {
          dp[k][i] = dp[k + 1][i - 1] + 2;
        } else if (i - k == 1) {
          dp[k][i] = 2;
        } else {
          dp[k][i] = 1;
        }
      } else {
        dp[k][i] = max(dp[k + 1][i], dp[k][i - 1]);
      }
    }
    for (auto nums : dp) {
      for (auto n : nums) {
        cout << n << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  return dp.back().back();
}

int main() {
  string s = "bbbab";
  cout << longestPalindromeSubseq(s) << endl;
  return 0;
}
