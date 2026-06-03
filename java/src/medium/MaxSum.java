package medium;

import java.util.HashMap;
import java.util.List;

public class MaxSum {
    public long maxSum(List<Integer> nums, int m, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int curSum = 0;
        int rs=0;
        for(int i=0;i<nums.size();i++){
            if(map.containsKey(nums.get(i))){
                map.put(nums.get(i),map.get(nums.get(i))+1);
            }else{
                map.put(nums.get(i),1);
            }
            curSum+=nums.get(i);
            if(i<k-1){
                continue;
            }
            if(map.size()>=m){
                rs= Math.max(curSum,rs);
            }
            if(map.get(nums.get(i-k+1))==1){
                map.remove(nums.get(i-k+1));
            }else{
                map.put(nums.get(i-k+1),map.get(nums.get(i-k+1))-1);
            }
            curSum-=nums.get(i-k+1);
        }
        return rs;
    }
}
