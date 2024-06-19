#include <vector>
using namespace std;

int search(vector<int> &arr, int target) {
  int left = 0;
  int right = arr.size() - 1;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[left] < arr[mid]) {
      if (arr[left] <= target && target <= arr[mid]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    } else if (arr[left] > arr[mid]) {
      if (arr[left] <= target || target <= arr[mid]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    } else {
      if (arr[left] != target)
        left++;
      else
        left = right;
    }
  }
  return arr[left] == target ? left : -1;
}
