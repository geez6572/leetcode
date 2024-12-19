package easy;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class MaxSum {
    public int calMax(int nums){
        int max=0;
        while(nums>0){
            max=Math.max(max,nums%10);
            nums=nums/10;
        }
        return max;
    }
    public int maxSum(int[] nums) {
        int[] map=new int[10];
        Arrays.fill(map,-1);
        int maxSum=-1;
        for(int i = 0; i < nums.length; i++){
            int cur=calMax(nums[i]);
            if(map[cur]!=-1){
                maxSum=Math.max(maxSum,nums[i]+map[cur]);
            }
            map[cur]= Math.max(nums[i],map[cur]);
        }
        return maxSum;
    }
}
