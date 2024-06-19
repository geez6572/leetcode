#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int rs = 0;
void recursion(string &s, int k, int left, int right) {
  if (right - left + 1 < k)
    return;
  vector<int> map;
  map.assign(26, 0);
  for (int i = left; i <= right; ++i) {
    map[s[i] - 'a']++;
  }
  int cur = 0;
  bool flag = true;
  int pre = left;
  for (int i = left; i <= right; ++i) {
    if (map[s[i] - 'a'] < k) {
      flag = false;
      recursion(s, k, pre, i - 1);
      pre = i + 1;
    } else if (i == right && !flag) {
      recursion(s, k, pre, i);
    }
  }
  if (flag)
    rs = max(rs, right - left + 1);
}

int longestSubstring(string s, int k) {
  recursion(s, k, 0, s.size() - 1);
  return rs;
}

int main() {
  string s = "bchhbbdefghiaaacb";
  cout << longestSubstring(s, 3);
  return 0;
}
