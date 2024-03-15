#include <climits>
#include <vector>
using namespace std;

int maximumProduct(vector<int> &nums) {
  int min1 = INT_MAX, min2 = INT_MAX;
  int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
  for (auto num : nums) {
    // 处理获取最大3个值的逻辑
    // 如果num大于最大值则依次往下赋值
    if (num > max1) {
      max3 = max2;
      max2 = max1;
      max1 = num;
    } else if (num > max2) {
      max3 = max2;
      max2 = num;
    } else if (num > max3) {
      max3 = num;
    }

    // 处理获取最小2个值的逻辑
    if (num < min1) {
      min2 = min1;
      min1 = num;
    } else if (num < min2) {
      min2 = num;
    }
  }
  return max1 * max2 * max3 > max1 * min1 * min2 ? max1 * max2 * max3
                                                 : max1 * min1 * min2;
}
