package easy;

import java.util.Arrays;

public class MinimumDifference {
    public int minimumDifference(int[] nums, int k) {
        Arrays.sort(nums);
        int rs=Integer.MAX_VALUE;
        for(int i=0;i<nums.length-k+1;i++) {
            rs=Math.min(rs,nums[i+k-1]-nums[i]);
        }
        return rs;
    }
}
