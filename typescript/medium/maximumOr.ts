function maximumOr(nums: number[], k: number): number {
  const prefix: number[] = new Array(nums.length).fill(0);
  const suffix: number[] = new Array(nums.length).fill(0);
  for (let i = 1; i < nums.length; i++) {
    prefix[i] = prefix[i - 1] | nums[i - 1];
    suffix[nums.length - 1 - i] = suffix[nums.length - i] |
      nums[nums.length - i];
  }

  let rs: number = 0;
  for (let i = 0; i < nums.length; i++) {
    rs = Math.max(rs, prefix[i] | suffix[i] | (nums[i] << k));
  }
  return rs;
}
