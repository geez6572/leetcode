#include <vector>
using namespace std;

// 顺序查找
int peakIndexInMountainArray(vector<int> &arr) {
  for (int i = 0; i < arr.size() - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      return i;
    }
  }
  return -1;
}

int peakIndexInMountainArray1(vector<int> &arr) {
  int left = 0;
  int right = arr.size() - 1;
  while (left < right) {
    int mid = (right + left) / 2;
    if (arr[mid] < arr[mid + 1]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left;
}
