#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class MyCmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};
vector<int> topKFrequent(vector<int> &nums, int k) {
  unordered_map<int, int> map;
  for (auto i : nums) {
    map[i]++;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> heap;
  for (auto p : map) {
    if (heap.size() == k) {
      heap.pop();
    }
    heap.push(p);
  }
  vector<int> rs;
  while (!heap.empty()) {
    rs.push_back(heap.top().first);
    heap.pop();
  }
  return rs;
}
