#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int openLock(vector<string> &deadends, string target) {
  unordered_set<string> set;
  for (auto &s : deadends)
    set.insert(s);
  if (set.count("0000"))
    return -1;
  return 0;
}
