#include <vector>
using namespace std;
vector<vector<int>> fileCombination(int target) {
  int left = 0;
  int right = 0;
  int cur_count = 0;
  vector<vector<int>> rs;
  while (right <= target / 2) {
    cur_count += right;
    if (cur_count > target) {
      cur_count -= left;
      left++;
    } else if (cur_count < target) {
      right++;
    } else {
      int s = left;
      int e = right;
      vector<int> temp;
      while (s <= e) {
        temp.push_back(s);
        s++;
      }
      rs.push_back(temp);
      left++;
    }
  }
  return rs;
}
