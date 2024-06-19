#include <iostream>
#include <list>
#include <vector>

using namespace std;

int iceBreakingGame(int num, int target) {
  list<int> l;
  for (int i = 0; i < num; ++i) {
    l.push_back(i);
  }
  auto cur = l.begin();
  while (l.size() > 1) {
    for (int i = 1; i < target; ++i) {
      cur++;
      if (cur == l.end())
        cur = l.begin();
    }
    cur = l.erase(cur);
    if (cur == l.end())
      cur = l.begin();
  }
  return *l.begin();
}

int main() {
  cout << iceBreakingGame(7, 4);
  return 0;
}
