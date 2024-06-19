#include <queue>
#include <vector>
using namespace std;

int findCircleNum(vector<vector<int>> &isConnected) {
  vector<int> visited(isConnected.size(), 0);
  int rs = 0;
  for (int i = 0; i < isConnected.size(); ++i) {
    if (visited[i] == 1)
      continue;
    queue<int> q;
    visited[i] = 1;
    rs++;
    q.push(i);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int k = 0; k < isConnected.size(); ++k) {
        if (visited[k] == 1 || isConnected[cur][k] == 0)
          continue;
        visited[k] = 1;
        q.push(k);
      }
    }
  }
  return rs;
}
