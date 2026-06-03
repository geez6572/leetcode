package easy;

public class MaximumCount {
    private int low_bound(int[]nums,int left,int right) {
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]>=0){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return right;
    }
    private int high_bound(int[]nums,int left,int right) {
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]<=0){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return left;
    }
    public int maximumCount(int[] nums) {
        int n = nums.length;
        int neg=low_bound(nums,0,n-1);
        int pos=high_bound(nums,neg+1,n-1);
        return Math.max(n-pos,neg+1);
    }
}
