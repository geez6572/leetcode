package medium;

public class MaximumOr {
    public long maximumOr(int[] nums, int k) {
        int[] prefix = new int[nums.length];
        int[] suffix = new int[nums.length];
        prefix[0] = 0;
        suffix[nums.length - 1] = 0;
        for (int i = 1; i < nums.length; i++) {
            prefix[i] = prefix[i - 1] | nums[i - 1];
            suffix[nums.length - 1 - i] = suffix[nums.length - i] | nums[nums.length - i];
        }
        long rs = 0;
        for (int i = 0; i < nums.length; i++) {
            rs = Math.max(rs, prefix[i] | suffix[i] | ((long) nums[i] << k));
        }
        return rs;
    }
}
