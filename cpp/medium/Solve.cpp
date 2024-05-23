#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<bool>> visited;
void dfs(vector<vector<char>> &grid, int x, int y) {
  visited[x][y] = true;
  for (int i = 0; i < 4; ++i) {
    int cur_x = x + dir[i][0];
    int cur_y = y + dir[i][1];
    if (cur_x >= 0 && cur_x < grid.size() && cur_y >= 0 &&
        cur_y < grid[0].size() && !visited[cur_x][cur_y] &&
        grid[cur_x][cur_y] == 'O') {
      dfs(grid, cur_x, cur_y);
    }
  }
}

void solve(vector<vector<char>> &grid) {
  visited = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), false));
  for (int i = 0; i < grid[0].size(); ++i) {
    if (grid[0][i] == 'O' && !visited[0][i])
      dfs(grid, 0, i);
    if (grid[grid.size() - 1][i] == 'O' && !visited[grid.size() - 1][i])
      dfs(grid, grid.size() - 1, i);
  }
  for (int i = 0; i < grid.size(); ++i) {
    if (grid[i][0] && !visited[i][0])
      dfs(grid, i, 0);
    if (grid[i][grid[0].size() - 1] && !visited[i][grid[0].size() - 1])
      dfs(grid, i, grid[0].size() - 1);
  }

  for (auto s : visited) {
    for (auto i : s) {
      cout << i << " ";
    }
    cout << endl;
  }

  for (int i = 1; i < grid.size() - 1; ++i) {
    for (int k = 1; k < grid[0].size() - 1; ++k) {
      if (grid[i][k] == 'O' && !visited[i][k])
        grid[i][k] = 'X';
    }
  }
}

int main() {
  vector<vector<char>> grid = {{'X', 'X', 'X', 'X'},
                               {'X', 'O', 'O', 'X'},
                               {'X', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'X'}};
  solve(grid);
  for (auto s : grid) {
    for (auto i : s) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
