#include <algorithm>
#include <vector>
using namespace std;

int findLHS(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int start = 0;
  int last = 1;
  int rs = 0;
  while (last < nums.size()) {
    if (nums[last] - nums[start] == 0) {
      last++;
    } else if (nums[last] - nums[start] == 1) {
      last++;
      rs = max(rs, last - start);
    } else {
      rs = max(rs, last - start);
      start++;
      while (nums[start - 1] == nums[start]) {
        start++;
      }
    }
  }
  return rs;
}
