#include <map>
#include <string>
using namespace std;

string sortString(string s) {
  map<char, int> m;
  for (auto c : s) {
    m[c]++;
  }
  string rs;
  bool seq = true;
  while (!m.empty()) {
    if (seq) {
      for (auto iter = m.begin(); iter != m.end();) {
        rs.push_back((*iter).first);
        iter->second = iter->second - 1;
        if (iter->second == 0) {
          m.erase(iter);
          continue;
        }
        iter++;
      }
    } else {
      for (auto iter = m.rbegin(); iter != m.rend();) {
        rs.push_back((*iter).first);
        iter->second = iter->second - 1;
        if (iter->second == 0) {
          continue;
        }
        iter++;
      }
    }
  }
}
