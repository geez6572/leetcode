#include <climits>
#include <string>
#include <vector>
using namespace std;

vector<string> commonChars(vector<string> &words) {
  vector<int> map(26, INT_MAX);
  for (auto str : words) {
    vector<int> cmp(26, 0);
    for (auto c : str) {
      cmp[c - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
      map[i] = min(cmp[i], map[i]);
    }
  }
  vector<string> rs;
  for (int i = 0; i < 26; ++i) {
    for (int k = 0; k < map[i]; ++k) {
      rs.push_back(string(1, i + 'a'));
    }
  }
  return rs;
}
