#include <iostream>
#include <vector>
using namespace std;
vector<int> countBits(int n) {
  vector<int> rs(n + 1, 0);
  for (int i = 0; i <= n; ++i) {
    int count = 0;
    int temp = i;
    while (temp) {
      if (temp & 1)
        ++count;
      temp = temp >> 1;
    }
    rs[i] = count;
  }
  return rs;
}

vector<int> countBits2(int n) {
  vector<int> rs(n + 1, 0);
  if (n == 0)
    return rs;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      rs[i] = rs[i - 1] + 1;
    } else {
      rs[i] = rs[i >> 1];
    }
  }
  return rs;
}

int main() {
  vector<int> rs = countBits(5);
  for (int num : rs) {
    cout << num << endl;
  }
  return 0;
}
