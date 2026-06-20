package hard;

import java.util.Arrays;

public class MinCut {

    private int[][] palMemo;
    private int[] dfsMemo;

    private boolean isPalindrome(String s, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (palMemo[start][end] == 1) {
            return true;
        } else if (palMemo[start][end] == 0) {
            return false;
        }
        boolean res = s.charAt(start) == s.charAt(end) && isPalindrome(s, start + 1, end - 1);
        palMemo[start][end] = res ? 1 : 0;
        return true;
    }

    private int dfs(String s, int start) {
        if (isPalindrome(s, start, s.length() - 1)) {
            return 0;
        }
        if (dfsMemo[start] != -1) {
            return dfsMemo[start];
        }
        int res = Integer.MAX_VALUE;
        for (int i = s.length() - 1; i >= start; i--) {
            if (isPalindrome(s, start, i)) {
                res = Math.min(res, dfs(s, i + 1) + 1);
            }
        }
        dfsMemo[start] = res;
        return res;
    }

    public int minCut(String s) {
        palMemo = new int[s.length()][s.length()];
        for (int i = 0; i < palMemo.length; i++) {
            Arrays.fill(palMemo[i], -1);
        }
        dfsMemo = new int[s.length()];
        Arrays.fill(dfsMemo, -1);
        int rs = dfs(s, 0);
        return rs;
    }

    public static void main(String[] args) {
        MinCut mc = new MinCut();
        System.out.println(
                mc.minCut("aab")
        );
    }
}
