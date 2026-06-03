function maxVowels(s: string, k: number): number {
  let rs = 0;
  let cur = 0;
  for (let i = 0; i < s.length; i++) {
    if (
      s[i] == "a" || s[i] == "e" || s[i] == "i" || s[i] == "o" || s[i] == "u"
    ) {
      cur++;
    }
    if (i < k - 1) {
      continue;
    }
    rs = Math.max(rs, cur);
    if (
      s[i - k + 1] == "a" || s[i - k + 1] == "e" || s[i - k + 1] == "i" ||
      s[i - k + 1] == "o" || s[i - k + 1] == "u"
    ) {
      cur--;
    }
  }
  return rs;
}
