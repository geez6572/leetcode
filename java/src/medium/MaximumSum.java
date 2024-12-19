package medium;

import java.util.ArrayList;
import java.util.HashMap;

public class MaximumSum {
    public int calM(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    public int maximumSum(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int rs=-1;
        for(int i=0; i<nums.length; i++){
            int cur=calM(nums[i]);
            if(map.containsKey(cur)){
                rs=Math.max(rs,map.get(cur)+nums[i]);
                map.put(cur, Math.max(nums[i],map.get(cur)));
            }else{
                map.put(cur,nums[i]);
            }
        }
        return rs;
    }

    public static void main(String[] args) {
    }
}
