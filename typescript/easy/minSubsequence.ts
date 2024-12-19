function minSubsequence(nums: number[]): number[] {
  nums.sort((a, b) => a - b);
  console.log(nums);
  let sum = 0;
  for (const num of nums) {
    sum += num;
  }
  const rs = [];
  let cur = 0;
  for (let i = nums.length - 1; i >= 0 && cur > sum - cur; i--) {
    cur = cur + nums[i];
    rs.push(nums[i]);
  }
  return rs;
}

const nums = [4, 3, 10, 9, 8];
const rs = minSubsequence(nums);
console.log(rs);
