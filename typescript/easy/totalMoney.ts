function totalMoney(n: number): number {
  const start = 28;
  const weeks = Math.floor(n / 7);
  const days = n % 7;
  const total = (start + (start + weeks * 7)) * weeks / 2 +
    ((1 + weeks) * 2 + days - 1) * days / 2;
  return total;
}
console.log(totalMoney(10));
