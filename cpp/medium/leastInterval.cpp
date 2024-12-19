#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int leastInterval(vector<char> &tasks, int n) {
  int maxCount = 0;
  int m = 0;
  vector<int> cnt(26, 0);
  for (auto c : tasks) {
    cnt[c - 'A']++;
    if (cnt[c - 'A'] > maxCount) {
      maxCount = cnt[c - 'A'];
      m = 1;
    } else if (cnt[c - 'A'] == maxCount) {
      m++;
    }
  }
  return max((int)tasks.size(), (n + 1) * (maxCount - 1) + m);
}

int main() {
  vector<char> tasks = {'A', 'C', 'A', 'B', 'D', 'B'};
  std::cout << leastInterval(tasks, 1);
}
