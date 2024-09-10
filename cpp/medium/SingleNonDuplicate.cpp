#include <utility>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums) {
  int left = 0;
  int right = nums.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    int n = -1;
    if (mid - 1 >= left && nums[mid - 1] == nums[mid]) {
      n = mid - 1;
    } else if (mid + 1 <= right && nums[mid + 1] == nums[mid]) {
      n = mid + 1;
    }
    if (n == -1)
      return nums[mid];
    if (n < mid)
      swap(n, mid);
    if ((mid - left) % 2)
      right = mid - 1;
    if ((right - n) % 2)
      left = n + 1;
  }
  return nums[left];
}

int singleNonDuplicate2(vector<int> &nums) {
  int left = 0;
  int right = nums.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (mid % 2 == 0) {
      if (mid + 1 <= right && nums[mid + 1] == nums[mid])
        left = mid + 1;
      else
        right = mid;
    } else {
      if (mid - 1 >= left && nums[mid - 1] == nums[mid])
        left = mid + 1;
      else
        right = mid;
    }
  }
  return nums[left];
}
