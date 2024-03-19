#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int> &nums, int k) {
  int left = 0;
  int right = 0;
  double count = 0;
  while (right < k) {
    count += nums[right++];
  }
  double max = count;
  while (right < nums.size()) {
    count = count - nums[left++] + nums[right++];
    if (count > max) {
      max = count;
    }
  }
  return max / (double)k;
}

int main() {
  vector<int> nums = {1, 12, -5, -6, 50, 3};
  cout << findMaxAverage(nums, 4);
  return 0;
}
