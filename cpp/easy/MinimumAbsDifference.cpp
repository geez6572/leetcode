#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
  sort(arr.begin(), arr.end());
  int gap = INT_MAX;
  for (int i = 1; i < arr.size(); ++i) {
    gap = min(gap, arr[i] - arr[i - 1]);
  }
  vector<vector<int>> rs;
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i] - arr[i - 1] == gap) {
      vector<int> temp = {arr[i - 1], arr[i]};
      rs.push_back(temp);
    }
  }
  return rs;
}
