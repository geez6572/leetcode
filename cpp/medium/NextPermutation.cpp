#include <algorithm>
#include <vector>
using namespace std;

int has_next(vector<int> &nums, int l) {
  int i;
  for (i = nums.size() - 1; i > l && nums[l] >= nums[i]; --i)
    ;
  if (i == l) {
    return -1;
  }
  return i;
}

void nextPermutation(vector<int> &nums) {
  if (nums.size() < 2)
    return;
  for (int i = nums.size() - 2; i >= 0; ++i) {
    int rs = has_next(nums, i);
    if (rs != -1) {
      int temp = nums[i];
      nums[i] = nums[rs];
      nums[rs] = temp;
      sort(nums.begin() + i + 1, nums.end());
      return;
    }
  }
  sort(nums.begin(), nums.end());
}

void nextPermutation2(vector<int> &nums) {
  if (nums.size() < 2)
    return;
  int i = nums.size() - 2;
  while (i >= 0 && nums[i] >= nums[i + 1])
    i--;
  if (i < 0)
    reverse(nums.begin(), nums.end());
  else {
    int k;
    for (k = nums.size() - 1; k > i && nums[i] >= nums[k]; k--)
      ;
    int temp = nums[k];
    nums[k] = nums[i];
    nums[i] = temp;
    reverse(nums.begin() + i + 1, nums.end());
  }
}
