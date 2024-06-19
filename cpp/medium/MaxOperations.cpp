#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> set;
int recursion(vector<int> &nums, int l, int r, int value) {
  if (r - l == 0) {
    return (nums.size() - (r - l + 1)) / 2;
  }
  if (r - l < 0) {
    return nums.size() / 2;
  }
  if (set[l][r])
    return set[l][r];
  int rs1 = (nums.size() - (r - l + 1)) / 2,
      rs2 = (nums.size() - (r - l + 1)) / 2,
      rs3 = (nums.size() - (r - l + 1)) / 2;
  if (nums[l] + nums[l + 1] == value) {
    rs1 = recursion(nums, l + 2, r, value);
  }

  if (nums[r] + nums[r - 1] == value) {
    rs2 = recursion(nums, l, r - 2, value);
  }
  if (nums[l] + nums[r] == value) {
    rs3 = recursion(nums, l + 1, r - 1, value);
  }
  set[l][r] = max(rs1, max(rs2, rs3));
  return set[l][r];
}

int maxOperations(vector<int> &nums) {
  if (nums.size() < 2)
    return 0;
  set = vector(nums.size(), vector(nums.size(), 0));
  int rs1 = recursion(nums, 2, nums.size() - 1, nums[0] + nums[1]);
  int rs2 =
      recursion(nums, 1, nums.size() - 2, nums[0] + nums[nums.size() - 1]);
  int rs3 = recursion(nums, 0, nums.size() - 3,
                      nums[nums.size() - 1] + nums[nums.size() - 2]);
  return max(rs1, max(rs2, rs3));
}

int main() {
  vector<int> nums = {2, 2, 1, 2, 1};
  cout << maxOperations(nums);
  return 0;
}
