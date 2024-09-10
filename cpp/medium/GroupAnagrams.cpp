#include <bitset>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  vector<vector<string>> rs;
  vector<pair<vector<int>, int>> m;
  unordered_map<string, vector<string>> map;
  for (auto &s : strs) {
    vector<int> count(26, 0);
    for (auto &c : s) {
      count[c - 'a']++;
    }
    int index = -1;
    for (auto [k, v] : m) {
      if (k == count) {
        index = v;
        break;
      }
    }
    if (index == -1) {
      vector<string> temp = {s};
      rs.push_back(temp);
      m.push_back(make_pair(count, rs.size() - 1));
    } else {
      rs[index].push_back(s);
    }
  }
  return rs;
}
