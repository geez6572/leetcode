function maxDistance(arrays: number[][]): number {
  let ans = 0;
  let max = Math.floor(Number.MIN_VALUE / 2);
  let min = Math.floor(Number.MAX_VALUE);
  for (const cur of arrays) {
    const curMax = cur[cur.length - 1];
    const curMin = cur[0];
    ans = Math.max(ans, max - curMin, curMax - min);
    max = Math.max(max, curMax);
    min = Math.min(min, curMin);
  }
  return ans;
}
let max = Number.MIN_VALUE / 2;
let min = Math.floor(Number.MAX_VALUE);
console.log(max);
console.log(min);
