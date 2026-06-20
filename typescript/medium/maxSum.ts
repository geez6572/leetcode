function maxSum(nums: number[], m: number, k: number): number {
  let cur: number = 0;
  let rs: number = 0;
  const map: Map<number, number> = new Map<number, number>();
  for (let i = 0; i < nums.length; i++) {
    if (map.has(nums[i])) {
      map.set(nums[i], map.get(nums[i])! + 1);
    } else {
      map.set(nums[i], 1);
    }
    cur += nums[i];
    if (i < k - 1) {
      continue;
    }
    if (map.size >= m && cur > rs) {
      rs = cur;
    }
    if (map.get(nums[i - k + 1])! > 1) {
      map.set(nums[i - k + 1], map.get(nums[i - k + 1])! - 1);
    } else {
      map.delete(nums[i - k + 1]);
    }
    cur -= nums[i - k + 1];
  }
  return rs;
}
