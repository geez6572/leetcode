#include <climits>
#include <vector>

using namespace std;

int findUnsortedSubarray(vector<int> &nums) {
  if (nums.size() <= 1) {
    return 0;
  }
  int max = nums[0];
  int first = INT_MAX;
  int last = INT_MAX;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] < nums[i - 1] || nums[i] < max) {
      int temp = i - 1;
      while (temp >= 0 && nums[temp] > nums[i]) {
        temp--;
      }
      first = min(first, (i - 1) > temp + 1 ? temp + 1 : i - 1);
      last = i;
    }
    if (nums[i] > max) {
      max = nums[i];
    }
  }
  if (first == last) {
    return 0;
  } else if (last == -1) {
    return nums.size();
  } else {
    return last - first + 1;
  }
}

int findUnsortedSubarray2(vector<int> &nums) {
  int max = INT_MIN, min = INT_MAX;
  int left = 0, right = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (max > nums[i])
      right = i;
    else
      max = nums[i];
    if (min < nums[nums.size() - 1 - i])
      left = nums.size() - 1 - i;
    else
      min = nums[nums.size() - 1 - i];
  }
  return right - left + 1;
}
