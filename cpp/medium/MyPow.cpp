

double myPow(double x, int n) {
  if (x == 0 || x == 1)
    return x;
  int flag = false;
  long l = n;
  if (l < 0) {
    l = -l;
    flag = true;
  }
  double rs = 1;
  double temp = x;
  long cur = 0;
  while (l > 0) {
    if (l & 1)
      rs *= temp;
    temp *= temp;
    l = l >> 1;
  }
  return flag ? 1.0 / rs : rs;
}
