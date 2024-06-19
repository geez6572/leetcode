#include <utility>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums) {
  int slow1 = 0;
  int slow2 = 0;
  int fast = 0;
  while (fast < nums.size()) {
    if (nums[fast] == 0) {
      swap(nums[fast], nums[slow1]);
      slow1++;
      if (slow2 < slow1)
        slow2 = slow1;
    } else if (nums[fast] == 1) {
      swap(nums[fast], nums[slow2]);
      slow2++;
    }
    fast++;
  }
}
