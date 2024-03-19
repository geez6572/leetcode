#include <vector>

using namespace std;

int findSpecialInteger(vector<int> &arr) {
  int target = arr.size() / 4;
  int count = 1;
  int rs = arr[0];
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i] == arr[i - 1]) {
      count++;
    } else {
      count = 1;
      rs = arr[i];
    }
    if (count > target) {
      return rs;
    }
  }
  return rs;
}
