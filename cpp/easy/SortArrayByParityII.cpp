#include <vector>
using namespace std;

vector<int> sortArrayByParityII(vector<int> &nums) {
  int slow = 0, fast = 0;
  for (int i = 0; i <= nums.size() / 2; ++i) {
    if (nums[fast] % 2) {
      swap(nums[slow], nums[fast]);
      slow++;
    }
    fast++;
  }
}
