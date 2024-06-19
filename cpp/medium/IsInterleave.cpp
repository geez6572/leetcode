#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str1;
string str2;
string str3;
bool dfs(int i1, int i2) {
  if (i1 == 0)
    return string(str2.begin(), str2.begin() + i2) ==
           string(str3.begin(), str3.begin() + i2);
  if (i2 == 0)
    return string(str1.begin(), str1.begin() + i1) ==
           string(str3.begin(), str3.begin() + i1);
  bool rs1 = false;
  bool rs2 = false;
  if (str1[i1 - 1] == str3[i1 + i2 - 1]) {
    rs1 = dfs(i1 - 1, i2);
  }
  if (str2[i2 - 1] == str3[i1 + i2 - 1]) {
    rs2 = dfs(i1, i2 - 1);
  }
  return rs1 || rs2;
}

bool isInterleave(string s1, string s2, string s3) {
  vector<vector<bool>> dp(s1.size() + 1, vector(s2.size() + 1, false));
  for (int i = 0; i <= s1.size(); ++i) {
    dp[i][0] = s1.substr(0, i) == s3.substr(0, i);
  }
  for (int i = 0; i <= s2.size(); ++i) {
    dp[0][i] = s2.substr(0, i) == s3.substr(0, i);
  }
  for (int i = 1; i < s1.size(); ++i) {
    for (int k = 1; k < s2.size(); ++k) {
      dp[i][k] = (s1[i - 1] == s3[i + k - 1] && dp[i - 1][k]) ||
                 (s2[k - 1] == s3[i + k - 1] && dp[i][k - 1]);
    }
  }
  return dp.back().back();
}

int main() {
  cout << isInterleave("aabcc", "dbbca", "aadbbcbcac");
  return 0;
}
