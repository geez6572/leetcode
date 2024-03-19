#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string longestWord(vector<string> &words) {
  sort(words.begin(), words.end(), [](string &a, string &b) {
    if (a.size() == b.size())
      return a > b;
    return a.size() < b.size();
  });
  unordered_set<string> set;
  int pre_len = words[0].size();
  set.insert("");
  string max_pattern;
  for (auto str : words) {
    if (str.size() - pre_len >= 2)
      break;
    if (set.count(string(str.begin(), str.end() - 1))) {
      max_pattern = str;
      set.insert(str);
    }
    pre_len = str.size();
  }
  return max_pattern;
}
