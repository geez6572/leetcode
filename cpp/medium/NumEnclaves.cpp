#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int numEnclaves(vector<vector<int>> &grid) {
  vector<vector<bool>> visited(grid.size(), vector(grid[0].size(), false));
  int rs = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int k = 0; k < grid[0].size(); ++k) {
      if (grid[i][k] == 0 || visited[i][k])
        continue;
      queue<pair<int, int>> q;
      bool flag = false;
      int cur = 0;
      visited[i][k] = true;
      q.push({i, k});
      while (!q.empty()) {
        pair<int, int> kv = q.front();
        q.pop();
        cur++;
        int x = kv.first;
        int y = kv.second;
        if (x + 1 == grid.size()) {
          flag = true;
        } else if (!visited[x + 1][y] && grid[x + 1][y] == 1) {
          visited[x + 1][y] = true;
          q.push({x + 1, y});
        }
        if (x - 1 == -1) {
          flag = true;
        } else if (!visited[x - 1][y] && grid[x - 1][y] == 1) {
          visited[x - 1][y] = true;
          q.push({x - 1, y});
        }
        if (y + 1 == grid[0].size()) {
          flag = true;
        } else if (!visited[x][y + 1] && grid[x][y + 1] == 1) {
          visited[x][y + 1] = true;
          q.push({x, y + 1});
        }
        if (y - 1 == -1) {
          flag = true;
        } else if (!visited[x][y - 1] && grid[x][y - 1] == 1) {
          visited[x][y - 1] = true;
          q.push({x, y - 1});
        }
      }
      if (!flag)
        rs += cur;
    }
  }
  return rs;
}

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(vector<vector<int>> &grid, int x, int y) {
  grid[x][y] = 0;
  for (int i = 0; i < 4; ++i) {
    int cur_x = x + dir[i][0];
    int cur_y = y + dir[i][1];
    if (cur_x >= 0 && cur_x < grid.size() && cur_y >= 0 &&
        cur_y < grid[0].size() && grid[cur_x][cur_y] == 1) {
      dfs(grid, cur_x, cur_y);
    }
  }
}

int numEnclaves2(vector<vector<int>> &grid) {
  for (int i = 0; i < grid[0].size(); ++i) {
    if (grid[0][i])
      dfs(grid, 0, i);
    if (grid[grid.size() - 1][i])
      dfs(grid, grid.size() - 1, i);
  }
  for (int i = 0; i < grid.size(); ++i) {
    if (grid[i][0])
      dfs(grid, i, 0);
    if (grid[i][grid[0].size() - 1])
      dfs(grid, i, grid[0].size() - 1);
  }
  int rs = 0;
  for (int i = 1; i < grid.size() - 1; ++i) {
    for (int k = 1; k < grid[0].size() - 1; ++k) {
      rs += grid[i][k];
    }
  }
  return rs;
}
