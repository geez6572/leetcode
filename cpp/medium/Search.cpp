#include <vector>
using namespace std;

int search(vector<int> &nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  while (l < r) {
    int mid = (r + l) / 2;
    if (target == nums[mid])
      return mid;
    if (nums[l] < nums[r]) {
      if (nums[mid] > target)
        r = mid - 1;
      else
        l = mid + 1;
    } else {
      if (nums[mid] > target) {
        if (target >= nums[l])
          r = mid - 1;
        else
          l++;
      } else {
        if (target <= nums[r])
          l = mid + 1;
        else
          r--;
      }
    }
  }
  return -1;
}

int search2(vector<int> &nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  while (l < r) {
    int mid = (r + l) / 2;
    if (target == nums[mid])
      return mid;
    if (nums[0] < nums[mid]) {
      if (target >= nums[0])
        r = mid - 1;
      else
        l = mid + 1;
    } else {
      if (target <= nums.back())
        l = mid + 1;
      else
        r = mid - 1;
    }
  }
  return -1;
}
