#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int minMutation(string startGene, string endGene, vector<string> &bank) {
  unordered_map<string, int> m;
  for (auto i = bank.begin(); i != bank.end(); i++) {
    m[*i] = 0;
  }
  if (!m.count(endGene))
    return -1;
  vector<char> cs = {'A', 'C', 'G', 'T'};
  queue<string> q;
  q.push(startGene);
  int rs = 0;
  while (!q.empty()) {
    int curLevel = q.size();
    for (int i = 0; i < curLevel; i++) {
      string curStr = q.front();
      if (curStr == endGene) {
        return rs;
      }
      q.pop();
      for (int k = 0; k < curStr.size(); k++) {
        for (auto c : cs) {
          if (curStr[k] != c) {
            char back = curStr[k];
            curStr[k] = c;
            if (m.count(curStr) && m[curStr] == 0) {
              q.push(curStr);
              m[curStr]++;
            }
            curStr[k] = back;
          }
        }
      }
    }
    rs++;
  }
  return -1;
}
