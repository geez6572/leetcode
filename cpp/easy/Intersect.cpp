
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> intersect1(vector<int> &nums1, vector<int> &nums2) {
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  vector<int> rs;
  int index1 = 0, index2 = 0;
  while (index1 < nums1.size() && index2 < nums2.size()) {
    if (nums1[index1] == nums2[index2]) {
      rs.push_back(nums1[index1]);
      index1++;
      index2++;
    } else if (nums1[index1] > nums2[index2]) {
      index2++;
    } else {
      index1++;
    }
  }
  return rs;
}

vector<int> intersect2(vector<int> &nums1, vector<int> &nums2) {
  unordered_map<int, int> map;
  vector<int> rs;
  for (int i = 0; i < nums1.size(); ++i) {
    if (map.count(nums1[i])) {
      ++map[nums1[i]];
    } else {
      map[nums1[i]] = 1;
    }
  }
  for (int i = 0; i < nums2.size(); ++i) {
    if (map.count(nums2[i]) && map[nums2[i]] > 0) {
      --map[nums2[i]];
      rs.push_back(nums2[i]);
    }
  }
  return rs;
}
