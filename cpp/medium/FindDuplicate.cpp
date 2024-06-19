#include <utility>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums) {
  int index = 0;
  while (index < nums.size()) {
    if (nums[index] != index) {
      if (nums[nums[index]] != nums[index])
        swap(nums[index], nums[nums[index]]);
      else
        return nums[index];
    } else {
      index++;
    }
  }
  return nums[0];
}
