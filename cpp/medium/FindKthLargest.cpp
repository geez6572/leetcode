#include <climits>
#include <vector>
using namespace std;

int quick(vector<int> &nums, int left, int right, int k) {
  int next_left = left;
  int next_right = right;
  int cur = nums[left];
  while (left < right) {
    while (left < right && nums[right] > cur) {
      right--;
    }
    if (left < right) {
      nums[left] = nums[right];
      left++;
    }
    while (left < right && nums[left] < cur) {
      left++;
    }
    if (left < right) {
      nums[right] = nums[left];
      right--;
    }
  }
  nums[left] = cur;
  if (left == k)
    return cur;
  if (left < k)
    return quick(nums, left + 1, next_right, k);
  return quick(nums, next_left, left - 1, k);
}

int findKthLargest(vector<int> &nums, int k) {
  return quick(nums, 0, nums.size() - 1, nums.size() - k);
}
