#include <iostream>
#include <vector>
using namespace std;

int crackNumber(int ciphertext) {
  if (ciphertext == 0)
    return 1;
  vector<int> dp(32, 0);
  int pre = ciphertext % 10;
  ciphertext /= 10;
  dp[0] = 1;
  dp[1] = 1;
  int index = 2;
  while (ciphertext) {
    int cur = ciphertext % 10;
    ciphertext /= 10;
    int comb = 0;
    if (cur * 10 + pre <= 25)
      comb = dp[index - 2];
    dp[index] = dp[index - 1] + comb;
    index++;
    pre = cur;
  }
  return dp[index - 1];
}

int main() {
  cout << crackNumber(216612);
  return 0;
}
