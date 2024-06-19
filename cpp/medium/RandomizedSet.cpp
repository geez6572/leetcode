#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <vector>
class RandomizedSet {
public:
  RandomizedSet() { srand((unsigned)time(NULL)); }

  bool insert(int val) {
    if (map.count(val))
      return false;
    nums.emplace_back(val);
    map[val] = nums.size() - 1;
    return true;
    ;
  }

  bool remove(int val) {
    if (!map.count(val))
      return false;
    int rm = map[val];
    int last = nums.back();
    nums[rm] = last;
    map[last] = rm;
    nums.pop_back();
    map.erase(val);
    return true;
  }

  int getRandom() {
    int ri = rand() % nums.size();
    return nums[ri];
  }

private:
  std::unordered_map<int, int> map;
  std::vector<int> nums;
};
