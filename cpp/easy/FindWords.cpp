#include <cctype>
#include <string>
#include <vector>
using namespace std;
void conMap(vector<int> &map, string s, int line) {
  for (auto c : s) {
    map[c - 'a'] = line;
  }
}

vector<string> findWords(vector<string> &words) {
  vector<int> map(26);
  string l1 = "qwertyuiop";
  string l2 = "asdfghjkl";
  string l3 = "zxcvbnm";
  conMap(map, l1, 1);
  conMap(map, l2, 2);
  conMap(map, l3, 3);
  vector<string> rs;
  for (auto &s : words) {
    bool flag = true;
    int curline = map[tolower(s[0]) - 'a'];
    for (auto &c : s) {
      if (map[tolower(c) - 'a'] != curline) {
        flag = false;
        break;
      }
    }
    if (flag)
      rs.push_back(s);
  }
  return rs;
}
