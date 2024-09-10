#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class myCompare {
public:
  bool operator()(pair<string, int> &a, pair<string, int> &b) {
    if (a.second == b.second)
      return a.first < b.first;
    return a.second > b.second;
  }
};

vector<string> topKFrequent(vector<string> &words, int k) {
  unordered_map<string, int> map;
  for (auto &s : words)
    map[s]++;
  priority_queue<pair<string, int>, vector<pair<string, int>>, myCompare> vec;
  for (const pair<string, int> &p : map) {
    vec.push(p);
  }
  vector<string> rs;
  for (int i = vec.size() - k; i < vec.size(); ++i) {
    rs.push_back(vec.top().first);
    vec.pop();
  }
  return rs;
}
