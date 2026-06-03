class RangeFreqQuery {
  private map: Map<number, number[]>;
  constructor(arr: number[]) {
    this.map = new Map<number, number[]>();
    for (let i = 0; i < arr.length; i++) {
      if (!this.map.has(arr[i])) {
        this.map.set(arr[i], new Array<number>());
      }
      this.map.get(arr[i])?.push(i);
    }
  }

  query(left: number, right: number, value: number): number {
    if (!this.map.has(value)) {
      return 0;
    }
    const arr = this.map.get(value)!;
    const l = this.lower_bound(arr, left);
    const r = this.upper_bound(arr, right);
    return r - l;
  }

  lower_bound(arr: number[], target: number) {
    let left = 0;
    let right = arr.length - 1;
    while (left <= right) {
      const mid = left + Math.floor((right - left) / 2);
      if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }

  upper_bound(arr: number[], target: number): number {
    let left = 0;
    let right = arr.length - 1;
    while (left <= right) {
      const mid = left + Math.floor((right - left) / 2);
      if (arr[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }
}
