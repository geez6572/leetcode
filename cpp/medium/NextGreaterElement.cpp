#include <algorithm>
#include <climits>
#include <vector>
int nextGreaterElement(int n) {
  std::vector<int> q;
  while (n) {
    if (q.empty() || q.back() <= (n % 10))
      q.push_back(n % 10);
    else
      break;
    n = n / 10;
  }
  if (n == 0)
    return -1;
  int index = 0;
  int cur = n % 10;
  n = n / 10;
  while (index < q.size() && q[index] <= cur)
    index++;
  n = n * 10 + q[index];
  q[index] = cur;
  std::sort(q.begin(), q.end());
  for (auto i : q) {
    if ((INT_MAX - i) / 10 > n)
      return -1;
    n = n * 10 + i;
  }
  return n;
}
