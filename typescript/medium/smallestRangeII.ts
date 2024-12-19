function smallestRangeII(nums: number[], k: number): number {
  nums.sort((a, b) => (a - b));
  let rs = nums[nums.length - 1] - nums[0];
  for (let i = 0; i < nums.length - 1; i++) {
    const curMax = Math.max(nums[i] + k, nums[nums.length - 1] - k);
    const curMin = Math.min(nums[0] + k, nums[i + 1] - k);
    rs = Math.min(curMax - curMin, rs);
  }
  return rs;
}
