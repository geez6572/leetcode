#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

double distance(const vector<int> &a, const vector<int> &b) {
  return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

double largestTriangleArea(vector<vector<int>> &points) {
  double rs = 0;
  for (int i = 0; i < points.size(); ++i) {
    for (int k = 0; k < points.size(); ++k) {
      if (k == i)
        continue;
      for (int l = 0; l < points.size(); ++l) {
        if (l == k || l == i)
          continue;
        double a = distance(points[i], points[k]);
        double b = distance(points[i], points[l]);
        double c = distance(points[l], points[k]);
        double s = (a + b + c) / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        rs = max(rs, area);
      }
    }
  }
  return rs;
}
