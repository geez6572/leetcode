#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> &nums) {
  vector<int> dp(nums.size(), 0);
  dp[0] = 1;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] > nums[i - 1]) {
      int temp = dp[i - 1];
      for (int index = i - 1; index >= 0; --index) {
        if (nums[index] < nums[i] && dp[index] > temp) {
          temp = dp[index];
        }
      }
      dp[i] = temp + 1;
    } else if (nums[i] == nums[i - 1]) {
      dp[i] = dp[i - 1];
    } else {

      int temp = 0;
      for (int index = i - 1; index >= 0; --index) {
        if (nums[index] < nums[i] && dp[index] > temp) {
          temp = dp[index];
        }
      }
      dp[i] = temp + 1;
    }
    for (auto i : dp) {
      cout << i << " ";
    }
    cout << endl;
  }
  int rs = 1;
  for (int i = 0; i < dp.size(); ++i) {
    if (dp[i] > rs) {
      rs = dp[i];
    }
  }
  return rs;
}

int main() {
  vector<int> nums = {0, 1, 0, 3, 2, 3};
  cout << lengthOfLIS(nums);
  return 0;
}
