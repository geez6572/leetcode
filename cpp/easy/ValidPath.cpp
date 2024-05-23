#include <vector>
using namespace std;

vector<int> father;
void init(int n) {
  father = vector<int>(n, 0);
  for (int i = 0; i < n; ++i) {
    father[i] = i;
  }
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

void join(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  father[u] = v;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
  init(n);
  for (auto vec : edges) {
    join(vec[0], vec[1]);
  }
  return isSame(source, destination);
}
