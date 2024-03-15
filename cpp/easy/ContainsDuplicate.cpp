#include <unordered_map>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int> &nums) {
  unordered_map<int, int> map;
  for (int num : nums) {
    if (map.count(num))
      return true;
    map[num] = 1;
  }
  return false;
}
