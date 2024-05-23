#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int longestConsecutive(vector<int> &nums) {
  if (nums.size() <= 1)
    return nums.size();
  sort(nums.begin(), nums.end());
  int rs = 1;
  int cur = 1;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] - nums[i - 1] == 1)
      cur++;
    else
      cur = 1;
    rs = max(cur, rs);
  }
  return rs;
}

int longestConsecutive2(vector<int> &nums) {
  unordered_map<int, int> map;
  int rs = 0;
  for (auto num : nums) {
    if (!map.count(num)) {
      int left = map.count(num - 1) ? map[num - 1] : 0;
      int right = map.count(num + 1) ? map[num + 1] : 0;
      int cur = left + right + 1;
      rs = max(rs, cur);
      map[num - left] = cur;
      map[num + right] = cur;
    }
  }
  return rs;
}
