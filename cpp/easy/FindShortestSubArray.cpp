#include <unordered_map>
#include <vector>
using namespace std;
struct Util {
  int count;
  int first;
  int last;
  Util(int x, int y, int z) : count(x), first(y), last(z) {}
};

int findShortestSubArray(vector<int> &nums) {
  unordered_map<int, Util *> map;
  for (int i = 0; i < nums.size(); ++i) {
    if (map.count(nums[i])) {
      map[nums[i]]->count++;
      map[nums[i]]->last = i;
    } else {
      Util *temp = new Util(1, i, i);
      map[nums[i]] = temp;
    }
  }
  int max = 0;
  int rs = nums.size() + 1;
  for (auto [key, value] : map) {
    if (value->count > max ||
        (value->count == max && rs < value->last - value->first + 1)) {
      max = value->count;
      rs = value->last - value->first + 1;
    }
  }
  return rs;
}
