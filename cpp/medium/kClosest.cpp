#include <queue>
#include <vector>
using namespace std;

struct cmp {
  bool operator()(vector<int> &a, vector<int> &b) {
    return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
  }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
  priority_queue<vector<int>, vector<vector<int>>, cmp> heap;
  for (int i = 0; i < points.size(); i++) {
    if (heap.size() == k) {
      heap.push(points[i]);
      heap.pop();
    } else {
      heap.push(points[i]);
    }
  }
  vector<vector<int>> rs;
  while (!heap.empty()) {
    rs.push_back(heap.top());
    heap.pop();
  }
  return rs;
}
