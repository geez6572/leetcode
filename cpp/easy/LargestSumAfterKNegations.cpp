#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int largestSumAfterKNegations(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end());
  int rs = 0;
  int min_value = -101;
  int index = 0;
  while (k && index < nums.size()) {
    if (nums[index] < 0) {
      rs += -nums[index];
      min_value = min(min_value, -nums[index]);
      k--;
    } else if (nums[index] > 0) {
      rs += nums[index];
      min_value = min(min_value, nums[index]);
    } else {
      k = 0;
    }
    index++;
  }

  while (k) {
    min_value = -min_value;
    rs += min_value * 2;
    k--;
  }
  while (index < nums.size()) {
    rs += nums[index--];
  }
  return rs;
}

int main() {
  vector<int> nums = {4, 2, 3};
  cout << largestSumAfterKNegations(nums, 1);
  return 0;
}
