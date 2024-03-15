
#include <stdint.h>
int hammingWeight(uint32_t n) {
  int rs = 0;
  while (n) {
    if (n & 1)
      ++rs;
    n = n >> 1;
  }
  return rs;
}
