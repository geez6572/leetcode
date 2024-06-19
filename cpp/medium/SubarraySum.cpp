#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int subarraySum(vector<int> &nums, int k) {
  int rs = (nums[0] == k ? 1 : 0);
  unordered_map<int, int> map;
  for (int i = 1; i < nums.size(); ++i) {
    nums[i] += nums[i - 1];
    if (nums[i] == k)
      rs++;
    if (map.count(nums[i] - k))
      rs += map[nums[i] - k];
    if (map.count(nums[i]))
      map[nums[i]]++;
    else
      map[nums[i]] = 1;
  }
  return rs;
}

int main() {
  vector<int> nums = {1, 1, 1};
  cout << subarraySum(nums, 2);
  return 0;
}
