#include <algorithm>
#include <vector>
using namespace std;

int pivotIndex(vector<int> &nums) {
  int sum = 0;
  for (int i = 1; i < nums.size(); ++i) {
    nums[i] = nums[i] + nums[i - 1];
  }
  if (nums.back() - nums.front() == 0)
    return 0;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i - 1] * 2 == (nums.back() - (nums[i] - nums[i - 2])))
      return i;
  }
  return -1;
}
