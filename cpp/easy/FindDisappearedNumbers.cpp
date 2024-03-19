#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> findDisappearedNumbers(vector<int> &nums) {
  vector<int> map(nums.size(), 0);
  vector<int> rs;
  for (auto i : nums) {
    map[i - 1]++;
  }
  for (int i = 0; i < map.size(); ++i) {
    if (map[i] == 0) {
      rs.push_back(i + 1);
    }
  }
  return rs;
}

int main() {
  vector<int> nums = {1, 2, 3, 5, 6};
  findDisappearedNumbers(nums);
  cout << "fdsa" << endl;
  int aa;
  return 0;
}
