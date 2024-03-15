#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> replaceElements(vector<int> &arr) {
  vector<int> rs = arr;
  sort(arr.begin(), arr.end());
  unordered_map<int, int> map;
  int a_index = arr.size() - 1;
  for (int i = 0; i < rs.size(); ++i) {
    if (map.count(rs[i])) {
      map[rs[i]]++;
    } else {
      map[rs[i]] = 1;
    }
    while (map.count(arr[a_index]) && map[arr[a_index]]) {
      map[arr[a_index]]--;
      a_index--;
    }
    rs[i] = arr[a_index];
  }
  return rs;
}

vector<int> replaceElements2(vector<int> &arr) {
  vector<int> rs = arr;
  sort(arr.begin(), arr.end());
  int a_index = arr.size() - 1;
  vector<int> map(arr[a_index] + 1, 0);
  for (int i = 0; i < rs.size() - 1; ++i) {
    map[rs[i]]++;
    while (map[arr[a_index]]) {
      map[arr[a_index]]--;
      a_index--;
    }
    rs[i] = arr[a_index];
  }
  rs[rs.size() - 1] = -1;
  return rs;
}

vector<int> replaceElements3(vector<int> &arr) {
  int max = -1;
  for (int i = arr.size() - 1; i >= 0; --i) {
    int temp = arr[i];
    arr[i] = max;
    if (temp > max)
      max = temp;
  }
  return arr;
}
