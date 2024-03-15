#include <climits>
#include <cmath>
#include <valarray>
#include <vector>
using namespace std;

int find_recent(int val, const vector<int> &heaters, int left, int right) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (heaters[mid] == val) {
      return mid;
    } else if (heaters[mid] < val) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  int closestIndex;
  if (left >= heaters.size()) // target 比 nums 中所有元素都大
    closestIndex = heaters.size() - 1;
  else if (right < 0) // target 比 nums 中所有元素都小
    closestIndex = 0;
  else // 选择距离 target 更近的那个元素
    closestIndex =
        abs(heaters[left] - val) < abs(heaters[right] - val) ? left : right;

  return closestIndex;
}

int findRadius(vector<int> &houses, vector<int> &heaters) {
  int left = 0;
  int right = heaters.size() - 1;
  int rs = -1;
  for (auto house : houses) {
    left = find_recent(house, heaters, left, right);
    if (abs(heaters[left] - house) > rs) {
      rs = abs(heaters[left] - house);
    }
  }
  return rs;
}
