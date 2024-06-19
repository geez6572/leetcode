#include <climits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
  unordered_map<string, int> map;
  for (int i = 0; i < list1.size(); ++i) {
    map[list1[i]] = i;
  }
  vector<string> rs;
  int min = INT_MAX;
  for (int i = 0; i < list2.size(); ++i) {
    if (map.count(list2[i])) {
      if (i + map[list2[i]] == min) {
        rs.push_back(list2[i]);
      } else if (i + map[list2[i]] < min) {
        rs.clear();
        rs.push_back(list2[i]);
        min = i + map[list2[i]];
      }
    }
  }
  return rs;
}
