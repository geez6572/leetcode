#include <vector>
using namespace std;

bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
  for (auto vec : pieces) {
    int index = 0;
    while (index < arr.size() && arr[index] != vec[0])
      index++;
    for (int i : vec) {
      if (index == arr.size() || i != arr[index])
        return false;
      index--;
    }
  }
  return true;
}

bool canFormArray2(vector<int> &arr, vector<vector<int>> &pieces) {
  vector<int> map(101, 0);
  for (int i = 0; i < arr.size(); ++i) {
    map[arr[i]] = i + 1;
  }
  for (auto vec : pieces) {
    for (int i = 0; i < vec.size(); ++i) {
      if (map[vec[i]] == 0 ||
          (i < vec.size() - 1 && map[arr[i + 1]] - map[arr[i]] != 1))
        return false;
    }
  }
  return true;
}
