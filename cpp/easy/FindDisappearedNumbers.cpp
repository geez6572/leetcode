#include <algorithm>
#include <vector>
using namespace std;
vector<int> findDisappearedNumbers(vector<int> &nums) {
  vector<int> map(nums.size(), 0);
  vector<int> rs;
  for (auto i : nums) {
    map[i - 1]++;
  }
  for (int i = 0; i < map.size(); ++i) {
    if (map[i] == 0) {
      rs.push_back(i + 1);
    }
  }
  return rs;
}
