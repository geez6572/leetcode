#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
  unordered_map<int, int> map;
  vector<vector<int>> rs;
  for (int i = 0; i < groupSizes.size(); i++) {
    if (map.count(groupSizes[i]) &&
        rs[map[groupSizes[i]]].size() < groupSizes[i]) {
      rs[map[groupSizes[i]]].push_back(i);
    } else {
      rs.push_back(vector(1, i));
      map[groupSizes[i]] = rs.size() - 1;
    }
  }
  return rs;
}
