package medium;

import java.util.HashMap;
import java.util.HashSet;

public class MaxVowels {
    public int maxVowels(String s, int k) {
        int mask = (1 << ('a' - 'a')) | (1 << ('e' - 'a')) | (1 << ('i' - 'a'))
                | (1 << ('o' - 'a')) | (1 << ('u' - 'a'));
        int left = 0;
        int right = 0;
        int rs = 0;
        int cur = 0;
        while (right < k) {
            if ((mask & (1 << (s.charAt(right) - 'a'))) != 0) {
                cur++;
            }
            right++;
        }
        rs = cur;
        while (right < s.length()) {
            if ((mask & (1 << (s.charAt(right) - 'a'))) != 0) {
                cur++;
            }
            right++;
            if ((mask & (1 << (s.charAt(left) - 'a'))) != 0) {
                cur--;
            }
            left++;
            rs = Math.max(cur, rs);
        }
        return rs;
    }
}
