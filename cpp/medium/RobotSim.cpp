#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
  unordered_multimap<int, int> map;
  for (auto ob : obstacles) {
    map.insert({ob[0], ob[1]});
  }
  vector<int> ordirate(2, 0);
  int direction = 3;
  int max = 0;
  for (auto c : commands) {
    if (c == -2) {
      direction = (direction - 1 + 4) % 4;
    } else if (c == -1) {
      direction = (direction + 1) % 4;
    } else {
      while (c--) {
        switch (direction) {
        case 0:
          ordirate[0]++;
          break;
        case 1:
          ordirate[1]--;
          break;
        case 2:
          ordirate[0]--;
          break;
        default:
          ordirate[1]++;
        }
        auto range = map.equal_range(ordirate[0]);
        for (auto it = range.first; it != range.second; it++) {
          if (it->second == ordirate[1]) {
            switch (direction) {
            case 0:
              ordirate[0]--;
              break;
            case 1:
              ordirate[1]++;
              break;
            case 2:
              ordirate[0]++;
              break;
            default:
              ordirate[1]--;
            }
            break;
          }
        }
        max = std::max(
            max, (ordirate[0] * ordirate[0] + (ordirate[1] * ordirate[1])));
      }
    }
  }
  return max;
}

int robotSim2(vector<int> &commands, vector<vector<int>> &obstacles) {
  vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  unordered_set<int> set;
  for (auto ob : obstacles) {
    set.insert(ob[0] * 60001 + ob[1]);
  }
  int rs = -1;
  int dir = 0;
  int cur_x = 0;
  int cur_y = 0;
  for (auto c : commands) {
    if (c == -1) {
      dir = (dir + 1) % 4;
    } else if (c == -2) {
      dir = (dir + 3) % 4;
    } else {
      while (c--) {
        if (!set.count((dirs[dir][0] + cur_x) * 60001 + cur_y + dirs[dir][1])) {
          cur_x += dirs[dir][0];
          cur_y += dirs[dir][1];
          rs = max(rs, cur_y * cur_y + cur_x * cur_x);
        } else {
          rs = max(rs, cur_y * cur_y + cur_x * cur_x);
          break;
        }
      }
    }
  }
  return rs;
}

int main() {
  vector<int> v1;
  v1.push_back(9);
  vector<int> v2;
  v2.push_back(9);
  cout << (v1 == v2);
  return 0;
}
