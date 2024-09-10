#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool modify(vector<vector<int>> &grid, int x, int y) {
  bool flag = false;
  for (int i = 0; i < 4; ++i) {
    int cur_x = x + dir[i][0];
    int cur_y = y + dir[i][1];
    if (cur_x >= 0 && cur_y >= 0 && cur_x < grid.size() &&
        cur_y < grid[0].size() && grid[cur_x][cur_y] == 1) {
      flag = true;
      grid[cur_x][cur_y] = 2;
    }
  }
  return flag;
}

int orangesRotting(vector<vector<int>> &grid) {
  vector<vector<int>> grid2(grid);
  int rs = 0;
  while (true) {
    bool changed = false;
    for (int i = 0; i < grid.size(); ++i) {
      for (int k = 0; k < grid[0].size(); ++k) {
        if (grid[i][k] == 2) {
          changed = modify(grid2, i, k) || changed;
        }
      }
    }
    if (changed) {
      rs++;
    } else {
      break;
    }
    grid = grid2;
  }
  for (int i = 0; i < grid.size(); ++i) {
    for (int k = 0; k < grid[0].size(); ++k) {
      if (grid[i][k] == 1) {
        return -1;
      }
    }
  }
  return rs;
}

int orangesRotting2(vector<vector<int>> &grid) {
  int cnt = 0;
  queue<pair<int, int>> q;
  int n = grid.size(), m = grid[0].size();
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < m; ++k) {
      if (grid[i][k] == 2) {
        q.emplace(i, k);

      } else if (grid[i][k] == 1) {
        cnt++;
      }
    }
  }

  int rs = 0;
  while (!q.empty()) {
    int level = q.size();
    bool flag = false;
    for (int k = 0; k < level; ++k) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int cur_x = x + dir[i][0];
        int cur_y = y + dir[i][1];
        if (cur_x >= 0 && cur_y >= 0 && cur_x < grid.size() &&
            cur_y < grid[0].size() && grid[cur_x][cur_y] == 1) {
          grid[cur_x][cur_y] = 2;
          q.emplace(cur_x, cur_y);
          cnt--;
          flag = true;
        }
      }
    }
    if (flag)
      rs++;
  }
  return cnt == 0 ? rs : -1;
}

int main() {
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 1}, {0, 1, 2}};
  cout << orangesRotting(grid);
  return 0;
}
