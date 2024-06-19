#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> &nums) {
  int left = 0;
  int right = nums.size() - 1;
  if (nums[left] <= nums[right])
    return nums[0];
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else if (nums[mid] < nums[left]) {
      right = mid;
    }
  }
  return nums[left];
}

int findMin2(vector<int> &nums) {
  int l = 0, r = nums.size() - 1;
  int x = nums[r];
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (nums[mid] <= x)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return nums[l];
}
int main() {
  vector<int> nums = {4, 5, 6, -1, 0, 1, 2};
  cout << findMin2(nums);
  return 0;
}
