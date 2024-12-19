function stringHash(s: string, k: number): string {
  let sum = 0;
  let rs = "";
  for (let i = 0; i < s.length; i++) {
    sum += s.charCodeAt(i) - "a".charCodeAt(0);
    if ((i + 1) % k == 0) {
      rs = rs + String.fromCharCode(sum % 26);
      sum = 0;
    }
  }
  return rs;
}
