#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int countBit(int num) {
  int count = 0;
  while (num) {
    if (num & 1)
      count++;
    num = num >> 1;
  }
  return count;
}

bool canSortArray(vector<int> &nums) {
  vector<int> bit(nums.size());
  for (int i = 0; i < nums.size(); ++i) {
    bit[i] = countBit(nums[i]);
  }
  int left = 0;
  int right = 0;
  while (right < nums.size()) {
    while (right + 1 < nums.size() && bit[right + 1] == bit[left])
      right++;
    if (right - left + 1 > 1)
      sort(nums.begin() + left, nums.begin() + right + 1);
    right++;
    left = right;
  }
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] < nums[i - 1])
      return false;
  }
  return true;
}

bool canSortArray2(vector<int> &nums) {
  vector<int> bit(nums.size());
  for (int i = 0; i < nums.size(); ++i) {
    bit[i] = countBit(nums[i]);
  }
  int left = 0;
  int right = 0;
  int pre_max = INT_MIN;
  int cur_min;
  int cur_max;
  while (right < nums.size()) {
    cur_min = nums[right];
    cur_max = nums[right];
    while (right + 1 < nums.size() && bit[right + 1] == bit[right]) {
      right++;
      cur_min = min(cur_min, nums[right]);
      cur_max = max(cur_max, nums[right]);
    }
    if (cur_min < pre_max)
      return false;
    pre_max = cur_max;
    right++;
  }
  return true;
}

int main() {
  vector<int> nums = {18, 3, 8};
  cout << canSortArray2(nums);
}
