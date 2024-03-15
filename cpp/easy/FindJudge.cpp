#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust) {
  if (trust.size() == n)
    return -1;
  vector<vector<int>> res(n, vector(2, 0));
  for (auto man : trust) {
    res[man[0] - 1][0] = man.size() - 1;
    for (int i = 1; i < man.size(); ++i) {
      res[man[i] - 1][1]++;
    }
  }
  for (int i = 0; i < res.size(); ++i) {
    if (res[i][0] == 0 && res[i][1] == n - 1)
      return i + 1;
  }
  return -1;
}
