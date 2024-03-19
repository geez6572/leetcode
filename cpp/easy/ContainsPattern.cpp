#include <iostream>
#include <vector>
using namespace std;

bool containsPattern(vector<int> &arr, int m, int k) {
  for (int i = 0; i < arr.size(); ++i) {
    int flag = false;
    for (int a = i; a < m; ++a) {
      flag = true;
      int slow = a;
      int fast = slow + m;
      int count = 1;
      while (fast < arr.size() && count <= k) {
        if (arr[slow] != arr[fast]) {
          break;
        }
        slow = fast;
        fast += m;
        count++;
      }
      if (count != k) {
        flag = false;
        break;
      }
    }
    if (flag) {
      return true;
    }
  }
  return false;
}

int main() {
  vector<int> arr = {1, 2, 1, 2, 1, 3};
  cout << containsPattern(arr, 2, 3);
  return 0;
}
