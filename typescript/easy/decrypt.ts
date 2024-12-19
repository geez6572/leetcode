function decrypt(code: number[], k: number): number[] {
  if (k == 0) {
    return Array(code.length).fill(0);
  }
  const circle = code.concat(code);
  let re = false;
  if (k < 0) {
    re = true;
    circle.reverse();
    k = -k;
  }
  const rs = [];
  let sum = 0;
  let left = 1;
  let right = 1;
  while (right <= k) {
    sum += circle[right];
    right++;
  }
  while (left - 1 < circle.length / 2) {
    rs.push(sum);
    sum = sum - circle[left];
    left++;
    sum = sum + circle[right];
    right++;
  }
  if (re) {
    return rs.reverse();
  }
  return rs;
}
