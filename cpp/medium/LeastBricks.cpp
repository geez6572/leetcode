#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

int leastBricks2(vector<vector<int>> &wall) {
  unordered_map<int, int> ktof;
  int count = 0;
  for (int i : wall[0])
    count += i;
  for (auto vec : wall) {
    int pre = 0;
    for (auto i : vec) {
      pre = pre + i;
      if (pre == count)
        continue;
      if (ktof.count(pre)) {
        ktof[pre]++;
      } else {
        ktof[pre] = 1;
      }
    }
  }
  int rs = wall.size();
  int all = wall.size();
  for (auto i : ktof) {
    rs = min(rs, all - i.second);
  }
  return rs;
}

int leastBricks(vector<vector<int>> &wall) {
  int all = 0;
  for (int i : wall[0]) {
    all += i;
  }
  vector<vector<int>> mark(wall.size(), vector(all, 0));
  for (int i = 0; i < wall.size(); ++i) {
    int pre = 0;
    for (auto l : wall[i]) {
      pre = pre + l;
      mark[i][pre] = 1;
    }
  }
  int rs = wall.size();
  for (int i = 1; i < all; ++i) {
    int cur = 0;
    for (int k = 0; k < wall.size(); ++k) {
      if (mark[k][i] == 0)
        rs++;
    }
    rs = min(rs, cur);
  }
  return rs;
}
