#include <vector>
using namespace std;

int count_len(vector<vector<int>> &grid, int x, int y) {
  int rs = 4;
  if (x - 1 >= 0 && grid[x - 1][y]) {
    rs--;
  }
  if (x + 1 < grid[0].size() && grid[x + 1][y]) {
    rs--;
  }
  if (y - 1 >= 0 && grid[x][y - 1]) {
    rs--;
  }
  if (y + 1 < grid.size() && grid[x][y + 1]) {
    rs--;
  }
  return rs;
}

int islandPerimeter(vector<vector<int>> &grid) {
  int rs = 0;
  for (int i = 0; i < grid.size(); ++i) {
    for (int k = 0; k < grid[0].size(); ++k) {
      rs += count_len(grid, k, i);
    }
  }
  return rs;
}
