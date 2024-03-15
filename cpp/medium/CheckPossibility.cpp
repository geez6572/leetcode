#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

bool checkPossibility(vector<int> &nums) {
  bool flag = false;
  int pre_max = INT_MIN;
  for (int i = 0; i < nums.size() - 1; ++i) {
    if (nums[i] > nums[i + 1]) {
      if (!flag) {
        if (nums[i + 1] < pre_max) {
          nums[i + 1] = nums[i];
        }
        flag = true;
      } else {
        return false;
      }
      pre_max = nums[i + 1];
    }
    pre_max = nums[i];
  }
  return true;
}
