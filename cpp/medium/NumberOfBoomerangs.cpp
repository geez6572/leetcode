#include <iterator>
#include <unordered_map>
#include <vector>
using namespace std;

int distance(vector<int> a, vector<int> b) {
  return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

int numberOfBoomerangs(vector<vector<int>> &points) {
  int rs = 0;
  for (int i = 0; i < points.size(); ++i) {
    unordered_map<int, int> map;
    for (int k = 0; k < points.size(); ++k) {
      if (k == i)
        continue;
      int dis = distance(points[i], points[k]);
      if (map.count(dis)) {
        map[dis]++;
      } else {
        map[dis] = 1;
      }
    }
    for (auto [_, v] : map) {
      for (int a = 0; a < v; ++a) {
        for (int b = a + 1; b < v; b++) {
          rs++;
        }
      }
    }
  }
  return rs * 2;
}
