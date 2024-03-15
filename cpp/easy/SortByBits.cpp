#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortByBits(vector<int> &arr) {
  sort(arr.begin(), arr.end());
  vector<int> count_one(arr.size());
  for (auto i : arr) {
    int count = 0;
    while (i) {
      if (i & 1)
        count++;
      i = i >> 1;
    }
    count_one.push_back(count);
  }
  for (int i = 1; i < count_one.size(); ++i) {
    int temp = count_one[i];
    int temp2 = arr[i];
    int index = i - 1;
    while (count_one[index] > temp) {
      count_one[index + 1] = count_one[index];
      arr[index + 1] = arr[index];
      index--;
    }
    arr[index + 1] = temp;
    count_one[index] = temp2;
  }
  return arr;
}
