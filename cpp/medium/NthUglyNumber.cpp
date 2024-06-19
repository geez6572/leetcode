#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int nthUglyNumber(int n) {
  unordered_set<long> set;
  vector<int> increase = {2, 3, 5};
  priority_queue<long, vector<long>, greater<long>> heap;
  set.insert(1L);
  heap.push(1L);
  int rs = 0;
  for (int i = 1; i <= n; ++i) {
    long cur = heap.top();
    heap.pop();
    rs = (int)cur;
    for (auto a : increase) {
      if (!set.count(cur * a)) {
        set.insert(cur * a);
        heap.push(cur * a);
      }
    }
  }
  return rs;
}

int nthUglyNumber2(int n) {
  vector<int> dp(n + 1);
  dp[1] = 1;
  int p2 = 1, p3 = 1, p5 = 1;
  for (int i = 2; i <= n; ++i) {
    int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
    dp[i] = min(min(num2, num3), num5);
    if (dp[i] == num2)
      p2++;
    if (dp[i] == num3)
      p3++;
    if (dp[i] == num5)
      p5++;
  }
  return dp[n];
}

int main() { return 0; }
