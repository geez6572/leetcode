function maxOperations(nums: number[], k: number): number {
  const map: Map<number, number> = new Map();
  let rs = 0;
  for (const cur of nums) {
    if (map.has(cur)) {
      rs++;
      const count: number = map.get(cur)!;
      if (count === 1) {
        map.delete(cur);
      } else {
        map.set(cur, count - 1);
      }
    } else {
      if (map.has(k - cur)) {
        map.set(k - cur, map.get(k - cur)! + 1);
      }
      map.set(k - cur, 1);
    }
  }
  return rs;
}

const nums: number[] = [
  2,
  5,
  4,
  4,
  1,
  3,
  4,
  4,
  1,
  4,
  4,
  1,
  2,
  1,
  2,
  2,
  3,
  2,
  4,
  2,
];

console.log(maxOperations(nums, 3));
