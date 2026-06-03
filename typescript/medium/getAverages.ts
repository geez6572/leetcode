function getAverages(nums: number[], k: number): number[] {
  let cur: number = 0;
  const l: number = 2 * k + 1;
  const avg: number[] = new Array<number>(nums.length).fill(-1);
  let left: number = 0;
  let right: number = 0;
  while (right < l) {
    cur += nums[right++];
  }
  avg[right - k - 1] = Math.floor(cur / l);
  while (right < nums.length) {
    cur += nums[right++];
    cur -= nums[left++];
    avg[right - k - 1] = Math.floor(cur / l);
  }
  return avg;
}
