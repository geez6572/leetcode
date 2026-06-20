package medium;

import java.util.Arrays;

public class SuccessfulPairs {
    private int lower_bound(int[] potions, long target) {
        int left = 0;
        int right = potions.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target <= potions[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int[] res = new int[n];
        Arrays.sort(potions);
        for (int i = 0; i < n; i++) {
            long target = (long) Math.ceil((success / (double) spells[i]));
            int index = lower_bound(potions, target);
            res[i] = potions.length - index - 1;
        }
        return res;
    }
}
