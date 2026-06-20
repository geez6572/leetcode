function maxRepeating(sequence: string, word: string): number {
  if (sequence.length < word.length) {
    return 0;
  }
  const dp = new Array<number>(sequence.length + 1).fill(0);
  let max = 0;
  for (let i = word.length; i <= sequence.length; i++) {
    if (sequence.substring(i - word.length, i) == word) {
      dp[i] = dp[i - word.length] + 1;
      if (dp[i] > max) {
        max = dp[i];
      }
    }
  }
  return max;
}
