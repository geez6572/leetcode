#include <vector>
using namespace std;

void duplicateZeros(vector<int> &arr) {
  int count_zero = 0;
  for (auto i : arr) {
    if (i == 0)
      count_zero++;
  }
  if (count_zero == 0) {
    return;
  }
  int index = arr.size() - 1;
  while (count_zero) {
    if (arr[index] != 0) {
      count_zero--;
    } else if (count_zero == 1) {
      break;
    } else {
      count_zero -= 2;
    }
    index--;
  }
  int last = arr.size() - 1;
  while (index >= 0) {
    if (arr[index]) {
      arr[last] = arr[index];
      last--;
      index--;
    } else {
      arr[last] = 0;
      arr[last - 1] = 0;
      last -= 2;
      index--;
    }
  }
}

void duplicateZeros2(vector<int> &arr) {
  int i = -1;
  int top = 0;
  while (top < arr.size()) {
    i++;
    top++;
    if (arr[i] == 0) {
      top++;
    }
  }

  int j = arr.size() - 1;
  if (top == arr.size() + 1) {
    arr[j] = 0;
    j--;
    i--;
  }
  while (i >= 0) {
    if (arr[i]) {
      arr[j] = arr[i];
      i--;
      j--;
    } else {
      arr[j] = 0;
      arr[j - 1] = 0;
      j -= 2;
    }
  }
}
