package medium;

import java.util.Arrays;

public class GetAverages {
    public int[] getAverages(int[] nums, int k) {
        int[] res = new int[nums.length];
        Arrays.fill(res, -1);
        int len=2*k+1;
        if(nums.length<len){
            return  res;
        }
        long cur=0;
        int left=0;
        int right=0;
        while(right<len){
            cur+=nums[right++];
        }
        res[right-k-1]=(int)cur/len;
        while(right<nums.length){
            cur+=nums[right++];
            cur-=nums[left++];
            res[right-k-1]=(int)cur/len;
        }

        return res;
    }
}
