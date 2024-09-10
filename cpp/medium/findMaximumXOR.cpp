#include <unordered_set>
#include <vector>
using namespace std;

static const int maxBit = 30;
int findMaximumXOR(vector<int> &nums) {
  int rs = 0;
  unordered_set<int> set;
  for (int i = maxBit; i >= 0; i--) {
    set.clear();
    for (auto num : nums) {
      set.insert(num >> i);
    }
    rs = (rs << 1) + 1;
    bool flag = false;
    for (auto num : nums) {
      if (set.count((num >> i) ^ rs)) {
        flag = true;
        break;
      }
    }

    if (!flag) {
      rs--;
    }
  }
  return rs;
}
