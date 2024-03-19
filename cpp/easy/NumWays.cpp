#include <vector>
using namespace std;

int rs = 0;
void recursion(vector<vector<int>> &mapping, int cur_man, int count,
               int max_count) {
  if (count > max_count) {
    return;
  }
  if (count == max_count) {
    if (cur_man == mapping.size() - 1) {
      rs++;
    }
    return;
  }
  for (const auto &i : mapping[cur_man]) {
    recursion(mapping, i, count + 1, max_count);
  }
}

int numWays(int n, vector<vector<int>> &relation, int k) {
  vector<vector<int>> mapping(n);
  for (const auto &i : relation) {
    mapping[i[0]].push_back(i[1]);
  }
  recursion(mapping, 0, 0, k);
  return rs;
}
