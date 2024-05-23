#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool uniqueOccurrences(vector<int> &arr) {
  unordered_map<int, int> map;
  for (auto i : arr) {
    if (map.count(i)) {
      map[i]++;
    } else {
      map[i] = 1;
    }
  }
  unordered_set<int> set;
  for (auto kv : map) {
    if (set.count(kv.second))
      return false;
    set.insert(kv.second);
  }
  return true;
}
