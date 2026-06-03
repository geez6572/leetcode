function numOfSubarrays(arr: number[], k: number, threshold: number): number {
  const sum: number = k * threshold;
  let cur: number = 0;
  let rs: number = 0;
  for (let i = 0; i < arr.length; i++) {
    cur += arr[i];
    if (i < k - 1) {
      continue;
    }
    if (cur >= sum) {
      rs++;
    }
    cur -= arr[i - k + 1];
  }
  return rs;
}
