function minOperations(nums: number[], k: number): number {
  let result = 0;
  for (const num of nums) {
    result = result ^ num;
  }
  result = result ^ k;
  let rs = 0;
  while (result > 0) {
    if ((result & 1) == 1) {
      rs++;
    }
    result = result >> 1;
  }
  return rs;
}
