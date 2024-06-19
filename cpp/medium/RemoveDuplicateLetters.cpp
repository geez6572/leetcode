#include <string>
#include <vector>
using namespace std;

string removeDuplicateLetters(string s) {
  vector<int> map(26, 0);
  vector<bool> isset(26, false);
  for (auto c : s) {
    map[c - 'a']++;
  }
  string rs;
  for (auto c : s) {
    if (isset[c - 'a']) {
      map[c - 'a']--;
      continue;
    }
    while (!rs.empty() && rs.back() > c && map[rs.back() - 'a']) {
      isset[rs.back() - 'a'] = false;
      rs.pop_back();
    }
    rs.push_back(c);
    isset[c - 'a'] = true;
    map[c - 'a']--;
  }
  return rs;
}
