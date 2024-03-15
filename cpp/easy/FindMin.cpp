#include <vector>

using namespace std;

int findMin(vector<int> &nums) {
  if (nums.size() == 1) {
    return nums[0];
  }
  int left = 0;
  int right = nums.size() - 1;
  int s = nums[0];
  int e = nums[nums.size() - 1];
  while (left < right) {
    int mid = (left + right) / 2;
    if (left == right) {
      return nums[left];
    }
    if (nums[mid] >= s) {
      left = mid + 1;
    } else if (nums[mid] <= e) {
      right = mid;
    }
  }
  return nums[0];
}
