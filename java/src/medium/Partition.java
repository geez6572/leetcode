package medium;

import java.util.ArrayList;
import java.util.List;

public class Partition {
    private boolean isPalindrome(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    private enum Status {
        UNKNOWN,
        YES,
        NO,
    }

    private Status[][] dp;
    private List<List<String>> res = new ArrayList<>();

    private void backTrace(String s, int start, List<String> cur) {
        if (start == s.length()) {
            res.add(new ArrayList<>(cur));
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (dp[start][i] == Status.UNKNOWN) {
                boolean temp = isPalindrome(s, start, i);
                if (temp) {
                    dp[start][i] = Status.YES;
                } else {
                    dp[start][i] = Status.NO;
                }
            }
            if (dp[start][i] == Status.YES) {
//                cur.addLast(s.substring(start, i + 1));
                backTrace(s, i + 1, cur);
//                cur.removeLast();

            }
        }
    }

    public List<List<String>> partition(String s) {
        dp = new Status[s.length()][s.length()];
        for(int i = 0; i < s.length(); i++) {
            for(int j = 0; j < s.length(); j++) {
                dp[i][j] = Status.UNKNOWN;
            }
        }
        backTrace(s, 0, new ArrayList<>(s.length()));
        return res;
    }

    public static void main(String[] args) {
        System.out.println(new Partition().partition("aab"));
    }
}
