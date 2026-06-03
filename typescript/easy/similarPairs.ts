function similarPairs(words: string[]): number {
  const map: Map<number, number> = new Map<number, number>();
  let rs = 0;
  for (const word of words) {
    let mask = 0;
    for (const c of word) {
      mask = mask | (1 << (c.charCodeAt(0) - "a".charCodeAt(0)));
    }
    if (!map.has(mask)) {
      map.set(mask, 0);
    }
    const pre = map.get(mask)!;
    rs += pre;
    map.set(mask, pre + 1);
  }
  return rs;
}
