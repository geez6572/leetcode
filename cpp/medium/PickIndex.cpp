#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
class Solution {
public:
  Solution(vector<int> &w) {
    map[0] = w[0];
    for (int i = 1; i < w.size(); ++i) {
      map[i] = map[0] + w[i];
    }
    srand(time(NULL));
  }

  int pickIndex() {
    int num = rand() % map.back();
    for (int i = 0; i < map.size(); ++i) {
      if (map[i] >= num)
        return i;
    }
    return -1;
  }

private:
  vector<int> map;
};
