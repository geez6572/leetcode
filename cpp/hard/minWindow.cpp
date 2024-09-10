#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string minWindow(string s, string t) {
  unordered_map<int, int> tm;
  for (auto c : t) {
    tm[c]++;
  }
  int left = 0;
  while (left < s.size() && tm[s[left]] == 0) {
    left++;
  }
  if (s.size() - left < t.size()) {
    return "";
  }
  int count = 0;
  int right = left;
  queue<int> next;
  while (count < t.size() && right < s.size()) {
    if (tm[s[right]]) {
      next.push(right);
      count++;
      tm[s[right]]--;
      if (count == t.size()) {
        break;
      }
    }
    right++;
  }
  if (count < t.size()) {
    return "";
  }
  string rs = string(s.begin() + left, s.begin() + right + 1);
  while (right < s.size()) {
    right++;
    while (right < s.size() && s[right] != s[left]) {
      right++;
    }
    left = next.front();
    next.pop();
    next.push(right);
    if (right < s.size() && rs.size() > (right + 1 - left)) {
      rs = string(s.begin() + left, s.begin() + right + 1);
    }
  }
  return rs;
}

string minWindow_rain(string s, string t) {
  if (s.size() < t.size())
    return "";
  vector<int> sm(128);
  vector<int> tm(128);
  for (auto c : s) {
    sm[c]++;
  }
  for (auto c : t) {
    tm[c]++;
    if (sm[c] < tm[c])
      return "";
  }
  vector<vector<bool>> visited(s.size(), vector(s.size(), false));
  function<string(int left, int right)> recur = [&](int left,
                                                    int right) -> string {
    if (right + 1 - left < t.size() || visited[left][right]) {
      return "";
    }
    while (tm[s[left]] == 0) {
      left++;
    }
    while (tm[s[right]] == 0) {
      right--;
    }
    string l = "";
    string r = "";

    visited[left][right] = true;
    if (sm[s[left]] > tm[s[left]]) {
      sm[s[left]]--;
      l = recur(left + 1, right);
      sm[s[left]]++;
    }
    if (sm[s[right]] > tm[s[right]]) {
      sm[s[right]]--;
      r = recur(left, right - 1);
      sm[s[right]]++;
    }
    if (l.empty() && r.empty()) {
      return string(s.begin() + left, s.begin() + right + 1);
    }
    if (l.empty()) {
      return r;
    }
    if (r.empty()) {
      return l;
    }
    return l.size() > r.size() ? r : l;
  };
  return recur(0, s.size() - 1);
}

int main() {
  cout << minWindow("ADOBECODEBANC", "ABC");
  return 0;
}
