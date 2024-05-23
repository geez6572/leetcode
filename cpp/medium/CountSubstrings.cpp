#include <string>
#include <vector>
using namespace std;

bool isPrime(string s, int start, int end) {
  while (start < end) {
    if (s[start] != s[end])
      return false;
  }
  return true;
}
int countSubstrings(string s) {
  vector<int> dp(s.size(), 0);
  dp[0] = 1;
  for (int i = 1; i < dp.size(); ++i) {
    int temp = 0;
    for (int k = 0; k <= i; ++k) {
      if (isPrime(s, k, i))
        temp++;
    }
    dp[i] = dp[i - 1] + temp;
  }
  return dp.back();
}

int countSubstrings2(string s) {
  vector<vector<bool>> dp(s.size(), vector(s.size(), false));
  int rs = 0;
  for (int i = 0; i <= s.size(); ++i) {
    for (int k = 0; k <= i; ++k) {
      bool flag = false;
      if ((k + 1 <= i - 1 && dp[k + 1][i - 1]) || k + 1 > i - 1)
        flag = true;
      if (flag && s[i] == s[k]) {
        dp[k][i] = true;
      }
      if (dp[k][i])
        rs++;
    }
  }
  return rs;
}
