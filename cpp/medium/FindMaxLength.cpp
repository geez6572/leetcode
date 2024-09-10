#include <algorithm>
#include <iostream>
#include <ostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findMaxLength(vector<int> &nums) {
  vector<int> dp(nums.size() + 1, 0);
  int rs = 0;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] == nums[i - 1]) {
      int start = i - dp[i];
      if (start == 0 || start == i)
        continue;
      if ((i - 1 - dp[i]) && nums[i] != nums[i - 1 - dp[i]]) {
        dp[i + 1] = dp[i] + 2 + dp[i - 1 - dp[i]];
      } else {
        int count = 0;
        for (int k = i - dp[i]; k < i; ++k) {
          if (nums[k])
            count++;
          else
            count--;
          if (nums[i] == 0 && count == -1) {
            dp[i + 1] = i - k;
            break;
          }
          if (nums[i] == 1 && count == 1) {
            dp[i + 1] = i - k;
            break;
          }
        }
      }
    } else
      dp[i + 1] = dp[i - 1] + 2;
    rs = max(rs, dp[i + 1]);
  }
  for (auto i : dp) {
    cout << i << endl;
  }
  return rs;
}

int findMaxLength2(vector<int> &nums) {
  vector<int> add(nums.size(), 0);
  add[0] = nums[0] == 0 ? -1 : 1;
  unordered_map<int, int> map;
  map[add[0]] = 0;
  int rs = 0;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] == 0) {
      add[i] = add[i - 1] - 1;
    } else {
      add[i] = add[i - 1] + 1;
    }
    if (add[i] == 0)
      rs = i + 1;
    else {
      if (map.count(add[i])) {
        rs = max(rs, i - map[add[i]]);
      }
      if (!map.count(add[i])) {
        map[add[i]] = i;
      }
    }
  }
  return rs;
}

int main() {
  vector<int> nums = {0, 0, 1, 0, 0, 0, 1, 1};

  cout << findMaxLength2(nums) << endl;
  return 0;
}
