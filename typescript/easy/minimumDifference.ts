function minimumDifference(nums: number[], k: number): number {
  nums.sort();
  let rs = Infinity;
  for (let i = 0; i < nums.length - k + 1; i++) {
    rs = Math.min(rs, nums[i + k - 1] - nums[i]);
  }
  return rs;
}
