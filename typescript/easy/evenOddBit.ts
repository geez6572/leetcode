function evenOddBit(n: number): number[] {
  const rs: number[] = new Array<number>(2).fill(0);
  for (let i = 0; n > 0; n = Math.floor(n / 2)) {
    rs[i] += n & 1;
    i = i ^ 1;
  }
  return rs;
}
