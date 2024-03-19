#include <string>
#include <vector>
using namespace std;

vector<string> letterCasePermutation(string s) {
  vector<int> change(s.size(), 0);
  vector<int> to_index;
  int num = 1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      change[i] = 'A' - 'a';
      num = num << 1;
      to_index.push_back(i);
    } else if (s[i] >= 'A' && s[i] <= 'Z') {
      change[i] = 'a' - 'A';
      num = num << 1;
      to_index.push_back(i);
    }
  }
  vector<string> rs;
  for (int i = 0; i < num; ++i) {
    int temp = i;
    int index = 0;
    string e = s;
    while (temp) {
      if (temp & 1) {
        e[to_index[index]] += change[to_index[index]];
      }
      temp = temp >> 1;
      index++;
    }
    rs.push_back(e);
  }
  return rs;
}
