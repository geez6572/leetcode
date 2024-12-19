function luckyNumbers(matrix: number[][]): number[] {
  const mins = new Array(matrix.length);
  mins.fill(Infinity);
  const maxs = new Array(matrix[0].length);
  maxs.fill(0);
  for (let i = 0; i < matrix.length; i++) {
    for (let k = 0; k < matrix[i].length; k++) {
      mins[i] = Math.min(mins[i], matrix[i][k]);
      maxs[k] = Math.max(maxs[k], matrix[i][k]);
    }
  }
  const rs: number[] = [];
  for (let i = 0; i < matrix.length; i++) {
    for (let k = 0; k < matrix[i].length; k++) {
      if (matrix[i][k] == mins[i] && matrix[i][k] == maxs[k]) {
        rs.push(matrix[i][k]);
      }
    }
  }
  return rs;
}

const nums = [[3, 7, 8], [9, 11, 13], [15, 16, 17]];
const rs = luckyNumbers(nums);
console.log(rs);
