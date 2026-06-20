function interchangeableRectangles(rectangles: number[][]): number {
  const map: Map<number, number> = new Map();
  let rs: number = 0;
  for (const rectangle of rectangles) {
    const ratio: number = rectangle[0] / rectangle[1];
    let exist: number = 0;
    if (map.has(ratio)) {
      exist = map.get(ratio)!;
    }
    map.set(ratio, exist + 1);
    rs += exist;
  }
  return rs;
}
