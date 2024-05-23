#include <vector>
using namespace std;

bool isPeak(vector<int> &nums, int index) {
  if (index == 0)
    return nums[index] > nums[index + 1];
  if (index == nums.size() - 1)
    return nums[index] > nums[index - 1];
  return nums[index] > nums[index - 1] && nums[index] > nums[index + 1];
}
int findPeakElement(vector<int> &nums) {
  if (nums.size() < 2) {
    return 0;
  }
  for (int i = 0; i < nums.size(); ++i) {
    if (isPeak(nums, i))
      return i;
  }
  return -1;
}
