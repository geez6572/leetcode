#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(int a, int b) {
  string s1 = to_string(a) + to_string(b);
  string s2 = to_string(b) + to_string(a);
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] > s2[i])
      return true;
    if (s1[i] < s2[i])
      return false;
  }
  return true;
}
string largestNumber(vector<int> &nums) {
  sort(nums.begin(), nums.end(), cmp);
  if (nums[0] == 0)
    return "0";
  string rs;
  for (auto i : nums) {
    rs += to_string(i);
  }
  return rs;
}

int main() {
  vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  cout << largestNumber(nums);
  return 0;
}
