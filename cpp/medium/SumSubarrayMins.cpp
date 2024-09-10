#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

int sumSubarrayMins(vector<int> &arr) {
  if (arr.empty())
    return 0;
  vector<vector<int>> dp = vector(2, vector(arr.size(), 0));
  int cur = 1;
  int mod = pow(10, 9) + 7;
  vector<int> rs(arr.size(), 0);
  for (int i = 0; i < arr.size(); ++i) {
    if (i > 0)
      rs[i] = rs[i - 1];
    for (int k = 0; k <= i; ++k) {
      if (k == i) {
        dp[cur][k] = arr[i];
      } else {
        dp[cur][k] = min(arr[i], dp[!cur][k]);
      }
      rs[i] = (rs[i] + (dp[cur][k] % mod)) % mod;
    }
    cur = !cur;
  }
  return rs.back();
}

int sumSubarrayMins2(vector<int> &arr) {
  vector<pair<int, int>> s;
  const int mod = pow(10, 9) + 7;
  int rs = arr[0];
  s.emplace_back(arr[0], 0);
  for (int i = 1; i < arr.size(); ++i) {
    while (!s.empty() && s.back().first > arr[i]) {
      s.pop_back();
    }
    s.emplace_back(arr[i], i);
    rs = (rs + s[0].first * (s[0].second + 1)) % mod;
    for (int k = 1; k < s.size(); ++k) {
      rs = (rs + s[k].first * (s[k].second - s[k - 1].second)) % mod;
    }
  }
  return rs;
}
