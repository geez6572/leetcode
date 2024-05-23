#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
  vector<vector<int>> dp(word1.size() + 1, vector(word2.size() + 1, 0));
  for (int i = 1; i <= word1.size(); ++i) {
    for (int k = 1; k <= word2.size(); ++k) {
      if (word1[i - 1] == word2[k - 1]) {
        dp[i][k] = dp[i - 1][k - 1] + 1;
      } else {
        dp[i][k] = max(dp[i][k - 1], dp[i - 1][k]);
      }
    }
  }
  return word1.size() + word2.size() - dp.back().back();
}

int minDistance2(string word1, string word2) {
  vector<vector<int>> dp(word1.size() + 1, vector(word2.size() + 1, 0));
  for (int i = 0; i < dp.size(); ++i) {
    dp[i][0] = i;
  }
  for (int i = 0; i < dp[0].size(); ++i) {
    dp[0][i] = i;
  }
  for (int i = 1; i <= word1.size(); ++i) {
    for (int k = 1; k <= word2.size(); ++k) {
      if (word1[i - 1] == word2[k - 1]) {
        dp[i][k] = dp[i - 1][k - 1];
      } else {
        dp[i][k] = min(dp[i][k - 1], dp[i - 1][k]) + 1;
      }
    }
  }
  return 0;
}
