function isPart(s: string, left: number, right: number): boolean {
  while (left < right) {
    if (s[left] != s[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

let dp: number[][];
let cur: string[];
let res: string[][];
function partition(s: string): string[][] {
  dp = new Array<Array<number>>(s.length);
  res = new Array();
  for (let i = 0; i < dp.length; i++) {
    dp[i] = new Array<number>(s.length);
    dp[i].fill(-1);
  }
  cur = new Array<string>();
  dfs(s, 0);
  return res;
}

function dfs(str: string, start: number) {
  if (start == str.length) {
    const add = new Array(cur.length);
    for (let i = 0; i < add.length; i++) {
      add[i] = cur[i];
    }
    res.push(cur);
    return;
  }

  for (let i = start; i < str.length; i++) {
    if (dp[start][i] == -1) {
      const r = isPart(str, start, i);
      if (r) {
        dp[start][i] = 1;
      } else {
        dp[start][i] = 0;
      }
    }
    if (dp[start][i] == 1) {
      cur.push(str.substring(start, i + 1));
      dfs(str, i + 1);
      cur.pop();
    }
  }
}
