#include <algorithm>
#include <vector>
using namespace std;

bool can_construct(int x, int y, int z) {
  return x + y > z && x + z > y && y + z > x;
}

int largestPerimeter(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int first = nums.size() - 3;
  int second = nums.size() - 2;
  int third = nums.size() - 1;
  while (third >= 0) {
    if (can_construct(nums[first], nums[second], nums[third])) {
      return nums[first] + nums[second] + nums[third];
    }
    first--;
    second--;
    third--;
  }
  return 0;
}
