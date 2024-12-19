function executeInstructions(
  n: number,
  startPos: number[],
  s: string,
): number[] {
  const rs = new Array(0);
  for (let i = 0; i < s.length; i++) {
    const cur = i;
    const curPos = { ...startPos };
    let items = 0;
    for (let k = 0; k < s.length; k++) {
      const diretion = s[(cur + k) % s.length];
      if (diretion == "R") {
        curPos[1]++;
      } else if (diretion == "L") {
        curPos[1]--;
      } else if (diretion == "U") {
        curPos[0]--;
      } else {
        curPos[0]++;
      }
      if (curPos[0] >= 0 && curPos[1] >= 0 && curPos[0] < n && curPos[1] < n) {
        items++;
      } else {
        break;
      }
    }
    rs.push(items);
  }
  return rs;
}

const startPos = [0, 1];
executeInstructions(3, startPos, "RRDDLU");
