function maximumXOR(nums: number[]): number {
  let max = -1;
  for (const num of nums) {
    max = Math.max(max, num);
  }
  let cur = 0;
  while ((max >> cur) > 0) {
    max = max | (1 << cur);
    cur++;
  }
  return max;
}
