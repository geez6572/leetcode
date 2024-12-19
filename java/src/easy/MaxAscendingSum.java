package easy;

public class MaxAscendingSum {
    public int maxAscendingSum(int[] nums) {
        int sum=0;
        int rs=0;
        for(int i=0;i<nums.length;i++){
            if(i==0||nums[i]>nums[i-1]){
                sum+=nums[i];
            }else{
                sum=nums[i];
            }
            rs= Math.max(sum,rs);
        }
        return rs;
    }
}
