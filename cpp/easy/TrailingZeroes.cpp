int trailingZeroes(int n) {
  int count = 0;
  int num = 1;
  for (int i = 1; i <= n; ++i) {
    int increase = i;
    while (increase % 10 == 0) {
      count++;
      increase /= 10;
    }
    num = num * increase;
    while (num % 10 == 0) {
      count++;
      num /= 10;
    }
  }
  return count;
}
