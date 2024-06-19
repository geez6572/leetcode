#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxOperations(vector<int> &nums) {
  if (nums.size() < 2)
    return 0;
  int op1 = nums[0];
  int op2 = nums[0] + nums[1];
  int index1 = 1;
  int index2 = 2;
  int count1 = 0;
  int count2 = 0;
  while (nums.size() >= 2 + index1) {
    if (nums[index1] == op1) {
      index1++;
      count1++;
    } else if (nums[index1] + nums[index1 + 1] == op1) {
      index1 += 2;
      count1++;
    } else {
      break;
    }
  }
  while (nums.size() >= 2 + index2) {
    if (nums[index2] == op2) {
      index2++;
      count2++;
    } else if (nums[index2] + nums[index2 + 1] == op2) {
      index2 += 2;
      count2++;
    } else {
      break;
    }
  }
  return max(count1, count2) + 1;
}

int main() {
  vector<int> nums = {1, 1, 1, 1, 2};
  cout << maxOperations(nums);
  return 0;
}
