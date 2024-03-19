#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int twoCitySchedCost(vector<vector<int>> &costs) {
  sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) {
    return abs(a[0] - a[1]) > abs(b[0] - b[1]);
  });
  int a = 0;
  int b = 0;
  int index = 0;
  int rs = 0;
  while (a < costs.size() / 2 && b < costs.size() / 2) {
    if (costs[index][0] - costs[index][1] > 0) {
      b++;
      rs += costs[index][1];
    } else {
      a++;
      rs += costs[index][0];
    }
    index++;
  }
  while (a < costs.size() / 2) {
    a++;
    rs += costs[index][0];
    index++;
  }

  while (b < costs.size() / 2) {
    b++;
    rs += costs[index][1];
    index++;
  }
  return rs;
}

int main() {
  vector<vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
  twoCitySchedCost(costs);
  return 0;
}
