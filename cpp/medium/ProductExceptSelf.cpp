#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
  int n = nums.size();
  vector<int> prefix(n);
  vector<int> suffix(n);
  prefix[0] = nums[0];
  suffix[n - 1] = nums[n - 1];
  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i - 1] * nums[i];
    suffix[n - i - 1] = suffix[n - i] * nums[n - i - 1];
  }
  vector<int> rs(n);
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      rs[i] = suffix[i + 1];
    } else if (i == n - 1) {
      rs[i] = prefix[i - 1];
    } else {
      rs[i] = prefix[i - 1] * suffix[i + 1];
    }
  }
  return rs;
}
