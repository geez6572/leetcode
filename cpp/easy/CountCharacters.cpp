#include <string>
#include <vector>
using namespace std;

int countCharacters(vector<string> &words, string chars) {
  vector<int> map(26, 0);
  for (auto i : chars) {
    map[i - 'a']++;
  }
  int rs = 0;
  for (auto str : words) {
    vector<int> temp(map);
    int flag = true;
    for (auto c : str) {
      temp[c - 'a']--;
      if (temp[c - 'a'] < 0) {
        flag = false;
        break;
      }
    }
    if (flag)
      rs += str.size();
  }
  return rs;
}
