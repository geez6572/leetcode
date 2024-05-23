#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int x,
         int y) {
  visited[x][y] = true;
  for (int i = 0; i < 4; ++i) {
    int next_x = x + dir[i][0];
    int next_y = y + dir[i][1];
    if (next_x < 0 || next_y < 0 || next_x >= heights.size() ||
        next_y >= heights[0].size() || visited[next_x][next_y] ||
        heights[x][y] > heights[next_x][next_y])
      continue;
    dfs(heights, visited, next_x, next_y);
  }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
  vector<vector<int>> rs;
  vector<vector<bool>> visited_o =
      vector(heights.size(), vector(heights[0].size(), false));
  vector<vector<bool>> visited_a =
      vector(heights.size(), vector(heights[0].size(), false));
  for (int i = 0; i < heights.size(); ++i) {
    dfs(heights, visited_o, i, 0);
    dfs(heights, visited_a, i, heights[0].size() - 1);
  }
  for (int i = 1; i < heights[0].size(); ++i) {
    dfs(heights, visited_o, 0, i);
    dfs(heights, visited_a, heights.size() - 1, i);
  }

  for (int i = 0; i < heights.size(); ++i) {
    for (int k = 0; k < heights[0].size(); ++k) {
      if (visited_a[i][k] && visited_o[i][k])
        rs.push_back({i, k});
    }
  }
  return rs;
}

int main() {
  vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                 {3, 2, 3, 4, 4},
                                 {2, 4, 5, 3, 1},
                                 {6, 7, 1, 4, 5},
                                 {5, 1, 1, 2, 4}};
  vector<vector<int>> rs = pacificAtlantic(heights);
  for (auto vec : rs) {
    for (auto i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
