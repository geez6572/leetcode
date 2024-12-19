function minOperations(nums: number[]): number {
  let dp1 = 0;
  let dp2 = 0;
  if (nums[0] == 0) {
    dp1 = 1;
  }
  for (let i = 1; i < nums.length; i++) {
    dp2 = dp1;
    if (nums[i] != nums[i - 1]) {
      dp2++;
    }
    dp1 = dp2;
  }
  return dp1;
}
