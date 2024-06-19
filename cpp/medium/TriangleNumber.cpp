#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int triangleNumber(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int rs = 0;
  for (int i = 0; i < nums.size() - 2; ++i) {
    for (int k = i + 1; k < nums.size() - 1; ++k) {
      int cur = nums[i] + nums[k];
      int left = k + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (nums[mid] >= cur) {
          right = mid - 1;
        } else if (nums[mid] < cur) {
          left = mid;
        }
      }
      if (nums[left] < cur) {
        rs += left - k;
      }
    }
  }
  return rs;
}

int main() {
  vector<int> nums = {2, 2, 3, 4};
  cout << triangleNumber(nums);
  return 0;
}
