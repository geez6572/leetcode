#include <algorithm>
#include <vector>
using namespace std;
class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) {
    this->nums = nums;
    target = k;
    sort(this->nums.begin(), this->nums.end());
  }

  int add(int val) { Q }

private:
  int target;
  vector<int> nums;
};
