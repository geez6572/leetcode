#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int> &nums, int k) {
  k = k % nums.size();
  int size = nums.size();
  vector<int> temp;
  temp.insert(temp.end(), nums.begin(), nums.end());
  temp.insert(temp.end(), nums.begin(), nums.end());
  nums.clear();
  nums.insert(nums.end(), temp.begin() + k, temp.begin() + k + size);
}

// O(1)空间复杂度
void rotate2(vector<int> &nums, int k) {
  k = k % nums.size();
  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}

int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  rotate(nums, 3);
  for (auto i : nums) {
    cout << i << " ";
  }
  return 0;
}
