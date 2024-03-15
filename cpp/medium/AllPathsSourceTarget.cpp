
#include <cmath>
#include <thread>
#include <vector>
using namespace std;

class Solution {
private:
  vector<vector<int>> rs;
  vector<int> path;
  void dfs(vector<vector<int>> &graph, int x) {
    if (x == graph.size() - 1) {
      rs.push_back(path);
      return;
    }
  }

public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {}
};
