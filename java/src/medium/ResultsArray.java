package medium;

import java.util.ArrayList;
import java.util.List;

public class ResultsArray {
    public int[] resultsArray(int[] nums, int k) {
        if(k==1){
            return nums;
        }
        int right=k;
        int increLen=1;
        for(int i=k-1;i>0;i--){
            if(nums[i]==nums[i-1]+1){
                increLen++;
            }else {
                break;
            }
        }
        int[] rs=new int[nums.length-k+1];
        int curIndex=0;
        if(increLen==k){
            rs[curIndex]=nums[right-1];
        }else{
            rs[curIndex]=-1;
        }
        curIndex++;
        while (right<nums.length){
            if(increLen==k){
                increLen--;
            }
            if(nums[right]>nums[right-1]){
                increLen++;
            }else{
                increLen=1;
            }
            right++;
            if(increLen==k){
                rs[curIndex]=nums[right-1];
            }else{
                rs[curIndex]=-1;
            }
            curIndex++;
        }
        return rs;
    }
}
