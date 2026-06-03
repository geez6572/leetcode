function minimumRecolors(blocks: string, k: number): number {
  let bCount: number = 0;
  let rs: number = k;
  for (let i = 0; i < blocks.length; i++) {
    if (blocks[i] === "B") {
      bCount++;
    }
    if (i < k - 1) {
      continue;
    }
    rs = Math.min(rs, k - bCount);
    if (blocks[i - k + 1] === "B") {
      bCount--;
    }
  }
  return rs;
}
