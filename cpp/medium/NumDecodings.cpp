#include <string>
#include <vector>
using namespace std;

int numDecodings(string s) {
  if (s[0] == '0')
    return 0;
  vector<int> dp(s.size() + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 1; i < s.size(); ++i) {
    int comb = (s[i - 1] - '0') * 10 + s[i] - '0';
    if (s[i] != '0')
      dp[i + 1] += dp[i];
    if (comb >= 10 && comb <= 26) {
      dp[i + 1] += dp[i - 1];
      if (dp[i + 1] == 0)
        return 0;
    }
  }
  return dp[s.size()];
}
