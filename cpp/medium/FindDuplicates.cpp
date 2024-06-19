#include <utility>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int> &nums) {
  int index = 0;
  while (index < nums.size()) {
    if (nums[index] != index + 1 && nums[nums[index] - 1] != nums[index]) {
      swap(nums[nums[index] - 1], nums[index]);
    } else {
      index++;
    }
  }
  vector<int> rs;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] != i + 1)
      rs.push_back(nums[i]);
  }
  return rs;
}
