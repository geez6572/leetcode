

#include <cmath>
#include <iostream>
int findNthDigit(int n) {
  int cur = 9;
  int i = 1;
  while (n > cur * i) {
    n -= i * cur;
    i++;
    cur = cur * 10;
  }
  int left = pow(10, i - 1);
  int base = left;
  int right = pow(10, i) - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if ((mid - base) * i >= n) {
      right = mid - 1;
    } else if ((mid - base + 1) * i < n) {
      left = mid + 1;
    } else {
      n -= (mid - base) * i;
      while (i - n > 0) {
        mid = mid / 10;
        i--;
      }
      return mid % 10;
    }
  }
  return 0;
}

int main() {
  std::cout << findNthDigit(100);
  return 0;
}
