#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
  int repalce = 0;
  int cur = 0;
  while (cur < nums.size()) {
    int pre = nums[cur];
    for (int i = 0; i < 2 && cur < nums.size() && nums[cur] == pre; ++i) {
      nums[repalce++] = nums[cur++];
    }
    if (cur < nums.size() && nums[cur] == pre)
      cur++;
  }
  return repalce;
}

int main() {
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  cout << removeDuplicates(nums);
  return 0;
}
