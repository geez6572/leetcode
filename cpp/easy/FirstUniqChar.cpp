#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int firstUniqChar(string s) {
  vector<int> map(26, -1);
  for (int i = 0; i < s.size(); ++i) {
    int key = s[i] - 'a';
    if (map[key] >= 0) {
      map[key] = -2;
    } else if (map[key] == -1) {
      map[key] = i;
    }
  }
  int rs = 1000000;
  for (int i : map) {
    if (i >= 0 && i < rs)
      rs = i;
  }
  return rs == 1000000 ? -1 : rs;
}
