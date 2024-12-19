function countVowelStrings(n: number): number {
  const strs = ["a", "e", "i", "o", "u"];
  const map = new Map([
    ["a", 0],
    ["e", 1],
    ["i", 2],
    ["o", 3],
    ["u", 4],
  ]);
  let rs = 0;
  const dfs = function (cur: string) {
    if (cur.length == n) {
      rs++;
    }
    let last: string = "a";
    if (cur.length > 0) {
      last = cur[cur.length - 1];
    }
    const start = map.get(last);
    if (start == undefined) {
      return;
    }
    for (let i = start; i < strs.length; i++) {
      dfs(cur + strs[i]);
    }
  };
  dfs("");
  return rs;
}
