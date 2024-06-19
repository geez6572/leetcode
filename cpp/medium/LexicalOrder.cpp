#include <vector>
using namespace std;

vector<int> lexicalOrder(int n) {
  vector<int> rs(n);
  rs[0] = 1;
  for (int i = 1; i < n; ++i) {
    if (rs[i - 1] * 10 <= n) {
      rs[i] = rs[i - 1] * 10;
    } else if (rs[i - 1] + 1 <= n && (rs[i - 1] + 1) % 10) {
      rs[i] = rs[i - 1] + 1;
    } else {
      int cur = rs[i - 1] / 10;
      while ((cur + 1) % 10) {
        cur /= 10;
      }
      rs[i] = cur + 1;
    }
  }
  return rs;
}
