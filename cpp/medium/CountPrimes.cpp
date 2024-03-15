#include <vector>

using namespace std;

int countPrimes(int n) {
  if (n <= 2) {
    return 0;
  }
  if (n == 3) {
    return 1;
  }
  int count = 1;
  for (int i = 3; i < n; i += 2) {
    int k = 3;
    for (k = 3; k * k <= i; k += 2) {
      if (i % k == 0) {
        break;
      }
    }
    if (i % k || k == 3) {
      count++;
    }
  }
  return count;
}

bool isPrime(int n) {
  if (n == 3)
    return true;
  for (int i = 3; i < n; i += 2) {
    int k = 3;
    for (k = 3; k * k <= i; k += 2) {
      if (i % k == 0) {
        return false;
      }
    }
  }
  return true;
}
int countPrimes2(int n) {
  vector<int> map(n, 1);
  int count = 0;
  for (int i = 2; i < n; ++i) {
    if (map[i]) {
      count++;
      if (i * i < n) {
        for (int k = i * i; k < n; k += i) {
          map[k] = 0;
        }
      }
    }
  }
  return count;
}
