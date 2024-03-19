#include <algorithm>
#include <vector>
using namespace std;

// 暴力
int maxCount(int m, int n, vector<vector<int>> &ops) {
  vector<vector<int>> matrix(m, vector(n, 0));
  int pre_max = 0;
  int count_max = 0;
  for (auto ordinates : ops) {
    for (int i = 0; i < ordinates[0]; ++i) {
      for (int k = 0; k < ordinates[1]; ++k) {
        matrix[i][k]++;
        if (matrix[i][k] > pre_max) {
          pre_max = matrix[i][k];
          count_max = 1;
        } else if (matrix[i][k] == pre_max) {
          count_max++;
        }
      }
    }
  }
  return count_max;
}

int maxCount2(int m, int n, vector<vector<int>> &ops) {
  int min_x = m;
  int min_y = n;
  for (auto ordinates : ops) {
    min_x = min(min_x, ordinates[0]);
    min_y = min(min_y, ordinates[1]);
  }
  return min_x * min_y;
}
