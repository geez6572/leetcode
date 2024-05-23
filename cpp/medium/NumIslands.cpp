#include <queue>
#include <utility>
#include <vector>
using namespace std;

int numIslands(vector<vector<char>> &grid) {
  vector<vector<bool>> visited(grid.size(), vector(grid[0].size(), false));
  int rs = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int k = 0; k < grid[0].size(); ++k) {
      if (grid[i][k] == '0' || visited[i][k])
        continue;
      rs++;
      queue<pair<int, int>> q;
      visited[i][k] = true;
      q.push({i, k});
      while (!q.empty()) {
        pair<int, int> kv = q.front();
        q.pop();
        int x = kv.first;
        int y = kv.second;
        if (x + 1 < grid.size() && !visited[x + 1][y] &&
            grid[x + 1][y] == '1') {
          visited[x + 1][y] = true;
          q.push({x + 1, y});
        }
        if (x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] == '1') {
          visited[x - 1][y] = true;
          q.push({x - 1, y});
        }
        if (y + 1 < grid[0].size() && !visited[x][y + 1] &&
            grid[x][y + 1] == '1') {
          visited[x][y + 1] = true;
          q.push({x, y + 1});
        }
        if (y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] == '1') {
          visited[x][y - 1] = true;
          q.push({x, y - 1});
        }
      }
    }
  }
  return rs;
}
