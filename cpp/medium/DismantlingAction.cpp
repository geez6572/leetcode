#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int dismantlingAction(string arr) {
  unordered_map<char, int> map;
  int left = 0;
  int right = 0;
  int rs = 0;
  while (right < arr.size()) {
    if (map.count(arr[right])) {
      left = max(map[arr[right]] + 1, left);
    }
    map[arr[right]] = right;
    rs = max(right - left + 1, rs);
  }
  return rs;
}

int dismantlingAction_dp(string arr) {
  unordered_map<char, int> map;
  vector<int> dp(arr.size(), 0);
  dp[0] = 1;
  map[arr[0]] = 0;
  int rs = 1;
  for (int i = 1; i < arr.size(); ++i) {
    int fi = -1;
    if (map.count(arr[i]))
      fi = map[arr[i]];
    if (fi < i - dp[i - 1])
      dp[i] = dp[i - 1] + 1;
    else
      dp[i] = i - fi;
    map[arr[i]] = i;
    rs = max(rs, dp[i]);
  }

  return rs;
}
