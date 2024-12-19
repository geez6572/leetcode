package medium;

import java.util.Arrays;

public class ResultsArrayII {
    public int[] resultsArray(int[] nums, int k) {
        if(k==1){
            return nums;
        }
        int increase=1;
        int[] rs=new int[nums.length-k+1];
        for(int i=1;i<nums.length;i++){
            if(nums[i]==nums[i-1]+1){
                increase++;
            }else{
                increase=1;
            }
            if(i>=k-1){
                if(increase>=k){
                    rs[i-k+1]=nums[i];
                }else{
                    rs[i-k+1]=-1;
                }
            }
        }
        return rs;
    }
}
