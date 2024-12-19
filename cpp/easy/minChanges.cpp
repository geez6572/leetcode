int minChanges(int n, int k) {
  int rs = 0;
  while (n > 0) {
    if (((n & 1) == 0) && ((k & 1) == 1)) {
      return -1;
    }
    if (((n & 1) == 1) && ((k & 1) == 0)) {
      rs++;
    }
    n = n >> 1;
    k = k >> 1;
  }
  return rs;
}
