#include <vector>

using namespace std;
int binarySearch(vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  int mid = -1;
  while (left <= right) {
    mid = left + (right - left) / 2;
    if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return mid;
}
vector<int> searchRange(vector<int> &nums, int target) {
  int index = binarySearch(nums, target);
  if (index == -1) {
    return {-1, -1};
  }
  int left = binarySearch(nums, target - 1);
  int right = binarySearch(nums, target + 1);
  return {left, right};
}
