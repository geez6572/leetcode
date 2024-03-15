#include <vector>
using namespace std;

int findKthPositive(vector<int> &arr, int k) {
  int l = 0;
  int r = arr.size() - 1;
  while (l < r) {
    int mid = (r + l) / 2;
    if (arr[mid] - mid - 1 < k) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  if (arr[l] - l - 1 >= k) {
    if (l == 0) {
      return k;
    }
    l--;
  }
  return arr[l] + k - (arr[l] - l - 1);
}
