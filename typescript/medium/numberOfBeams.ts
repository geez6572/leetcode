function numberOfBeams(bank: string[]): number {
  let rs = 0;
  let pre = 0;
  for (let i = 0; i < bank.length; i++) {
    let cur = 0;
    for (let k = 0; k < bank[i].length; k++) {
      if (bank[i].charAt(k) == "1") {
        cur++;
      }
    }
    if (cur != 0) {
      rs += pre * cur;
      pre = cur;
    }
  }
  return rs;
}

let bank = ["011001", "000000", "010100", "001000"];
numberOfBeams(bank);
