#include <algorithm>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle) {
  for (int i = 1; i < triangle.size(); ++i) {
    for (int k = 0; k <= i; ++k) {
      if (k == 0) {
        triangle[i][k] += triangle[i - 1][k];
        continue;
      }
      if (k == i) {
        triangle[i][k] += triangle[i - 1][k - 1];
        continue;
      }
      triangle[i][k] += min(triangle[i - 1][k], triangle[i - 1][k - 1]);
    }
  }
  int rs = triangle.back()[0];
  for (auto i : triangle.back()) {
    rs = min(rs, i);
  }
  return rs;
}
