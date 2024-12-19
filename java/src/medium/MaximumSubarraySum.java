package medium;

import java.util.HashMap;

public class MaximumSubarraySum {
    public long maximumSubarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int left=0;
        int right=0;
        int sum=0;
        while(right<k){
            if(map.containsKey(nums[right])){
                map.put(nums[right], map.get(nums[right]) + 1);
            }else{
                map.put(nums[right], 1);
            }
            sum+=nums[right];
            right++;
        }
        int rs=0;
        if(map.size()==k){
            rs=sum;
        }
        while(right<nums.length){
            if(map.containsKey(nums[right])){
                map.put(nums[right], map.get(nums[right]) + 1);
            }else{
                map.put(nums[right], 1);
            }
            if(map.get(nums[left])==1){
                map.remove(nums[left]);
            }else{
                map.put(nums[left], map.get(nums[left]) - 1);
            }
            sum-=nums[left];
            sum+=nums[right];
            left++;
            right++;
            if(map.size()==k){
                rs=Math.max(rs,sum);
            }
        }
        return rs;
    }

    public static void main(String[] args) {
        MaximumSubarraySum maximumSubarraySum = new MaximumSubarraySum();
        int[] nums={1,1,1,7,8,9};
        System.out.println(maximumSubarraySum.maximumSubarraySum(nums, 3));
    }
}
