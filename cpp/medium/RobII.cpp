#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int> &nums) {
  if (nums.size() == 1)
    return nums[0];
  if (nums.size() == 2)
    return max(nums[0], nums[1]);

  vector<int> dp1(nums.size(), 0);
  vector<int> dp2(nums.size(), 0);
  dp1[0] = nums[0];
  dp1[1] = max(dp1[0], nums[1]);
  dp2[1] = nums[1];
  dp2[2] = max(dp2[1], nums[2]);
  for (int i = 2; i < nums.size() - 1; ++i) {
    dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
    dp2[i + 1] = max(dp2[i], dp2[i - 1] + nums[i + 1]);
  }
  return max(dp1[dp1.size() - 2], dp2.back());
}

int main() {
  vector<int> nums = {2, 2, 4, 3, 2, 5};
  cout << rob(nums);
  return 0;
}
