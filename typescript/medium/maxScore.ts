function maxScore(cardPoints: number[], k: number): number {
  let rs: number = 0;
  let cur: number = 0;
  if (cardPoints.length === k) {
    for (const card of cardPoints) {
      rs += card;
    }
    return rs;
  }
  let left = cardPoints.length - k;
  let right = left;
  while (right != 0) {
    cur += cardPoints[right];
    right = (right + 1) % cardPoints.length;
  }
  rs = cur;
  while (right < k) {
    cur += cardPoints[right++];
    cur -= cardPoints[left];
    left = (left + 1) % cardPoints.length;
    rs = Math.max(cur, rs);
  }
  return rs;
}
