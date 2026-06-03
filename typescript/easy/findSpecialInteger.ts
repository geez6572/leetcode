function findSpecialInteger(arr: number[]): number {
  let sum: number = 0;
  for (let i = 0; i < arr.length; i++) {
    sum += arr[i];
  }
  let left: number = 0;
  let right: number = arr.length - 1;
  while (left <= right) {
    const mid: number = left + (right - left) / 2;
  }
}
