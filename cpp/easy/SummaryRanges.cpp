#include <ios>
#include <string>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int> &nums) {
  int left = 0;
  int right = 0;
  vector<string> rs;
  while (right < nums.size()) {
    if (right != nums.size() - 1 && nums[right] + 1 == nums[right + 1])
      right++;
    else {
      if (left == right) {
        rs.push_back(to_string(nums[left]));
      } else {
        string s = to_string(nums[left]) + "->" + to_string(nums[right]);
        rs.push_back(s);
      }
      right++;
      left = right;
    }
  }
  return rs;
}

int main() {
  vector<int> nums = {0, 1, 2, 4, 5, 7};
  summaryRanges(nums);
  return 0;
}
