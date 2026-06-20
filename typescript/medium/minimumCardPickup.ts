function minimumCardPickup(cards: number[]): number {
  const map: Map<number, number> = new Map();
  let rs: number = cards.length + 1;
  for (let i = 0; i < cards.length; i++) {
    if (map.has(cards[i])) {
      rs = Math.min(rs, i - map.get(cards[i])! + 1);
    }
    map.set(cards[i], i);
  }
  return rs === cards.length + 1 ? -1 : rs;
}
