package easy;

public class MinOperations {
    public int minOperations(int[] nums) {
        int left=0;
        int right=2;
        int operators=0;
        while(left<nums.length){
            if(nums[left]==1){
                left++;
                right++;
            }else{
                if(right>=nums.length){
                    return -1;
                }
                operators++;
                for(int i=left;i<=right;i++){
                    nums[i]=nums[i]^1;
                }
            }
        }
        return operators;
    }
}
