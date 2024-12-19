function truncateSentence(s: string, k: number): string {
  let index = 0;
  let rs = "";
  let count = 0;
  while (index < s.length && count < k) {
    while (index < s.length && s[index] == " ") {
      index++;
    }
    while (index < s.length && s[index] != " ") {
      rs = rs + s[index];
      index++;
    }
    if (count < k - 1) {
      rs += " ";
    }
    count++;
  }
  return rs;
}
