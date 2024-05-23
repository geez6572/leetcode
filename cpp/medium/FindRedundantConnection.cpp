#include <vector>
using namespace std;

vector<int> father;
void init(int n) {
  father = vector(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    father[i] = i;
}

int find(int u) {
  if (u == father[u])
    return u;
  father[u] = find(father[u]);
  return father[u];
}

bool isSame(int u, int v) {
  u = find(u);
  v = find(v);
  return u == v;
}

bool join(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return true;
  father[v] = u;
  return false;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges) {
  init(edges.size());
  for (auto vec : edges) {
    if (join(vec[0], vec[1]))
      return vec;
  }
  return {};
}
