#include <cmath>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> rs;
  vector<bool> visited;
  vector<int> path;
  void dfs(vector<vector<int>> &graph, int x) {
    path.push_back(x);
    if (x == graph.size() - 1)
      rs.push_back(path);
    for (int i = 0; i < graph[x].size(); ++i) {
      if (!visited[graph[x][i]]) {
        dfs(graph, graph[x][i]);
      }
    }
    path.pop_back();
  }

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    visited = vector(graph[0].size(), false);
    dfs(graph, 0);
    return rs;
  }
};

int main() {
  Solution s;
  return 0;
}
