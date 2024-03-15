
#include <bitset>
#include <iostream>
#include <limits>
#include <stdint.h>
using namespace std;
uint32_t reverseBits(uint32_t n) {
  uint32_t rs = 0;
  for (int i = 0; i < 32 && n; i++) {
    rs = rs + ((n & 1) << (31 - i));
  }
  return rs;
}

int main() {
  uint32_t p = 0b00000010100101000001111010011100;
  reverseBits(p);
  cout << sizeof(int *);
  return 0;
}
