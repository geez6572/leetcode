function countCompleteDayPairs(hours: number[]): number {
  const m = new Map();
  let rs = 0;
  for (let i = 0; i < hours.length; i++) {
    if (m.has((24 - hours[i] % 24) % 24)) {
      rs += m.get((24 - hours[i] % 24) % 24);
    }
    if (m.has(hours[i] % 24)) {
      m.set(hours[i] % 24, m.get(hours[i] % 24) + 1);
    } else {
      m.set(hours[i] % 24, 1);
    }
  }
  return rs;
}

let hours = [12, 12, 30, 24, 24];
countCompleteDayPairs(hours);
