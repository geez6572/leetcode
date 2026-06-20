function canBeValid(s: string, locked: string): boolean {
  let maxLeft: number = 0;
  let minLeft: number = 0;
  for (let i = 0; i < s.length; i++) {
    if (locked[i] == "0") {
      minLeft--;
      maxLeft++;
    } else {
      const increasement: number = s[i] == "(" ? 1 : -1;
      maxLeft += increasement;
      if (maxLeft < 0) {
        return false;
      }
      minLeft += increasement;
    }
    if (minLeft < 0) {
      minLeft = 1;
    }
  }
  return minLeft == 0;
}
