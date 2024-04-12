#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
bool wordBreak(string s, vector<string> &wordDict) {
  unordered_set<string> set(wordDict.begin(), wordDict.end());
  vector<bool> dp(s.size() + 1, false);
  dp[0] = true;
  for (int i = 1; i <= s.size(); ++i) {
    for (int k = 1; k <= i; k++) {
      string word = s.substr(i - k, k);
      if (set.count(word) && dp[i - k]) {
        dp[i] = true;
        break;
      }
    }
  }
  return dp[s.size()];
}

int main() {
  string s = "catsandog";
  vector<string> dict = {"cats", "dog", "sand", "and", "cat"};
  cout << wordBreak(s, dict);
  return 0;
}
