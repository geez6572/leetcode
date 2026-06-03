package medium;

public class FindIndices {
    class Pair{
        int index;
        int value;
    }
    public int[] findIndices(int[] nums, int indexDifference, int valueDifference) {
        int left=0;
        int right=indexDifference;
        Pair min=new Pair();
        min.value=Integer.MAX_VALUE;
        Pair max=new Pair();
        max.value=Integer.MIN_VALUE;
        while(right<nums.length){
            if(nums[left]<min.value){
                min.value=nums[left];
                min.index=left;
            }
            if(nums[left]>max.value){
                max.value=nums[left];
                max.index=left;
            }
            if(nums[right]-min.value>=valueDifference){
                return new int[]{min.index,right};
            }
            if(max.value-nums[right]>=valueDifference){
                return new int[]{max.index,right};
            }
            left++;
            right++;
        }
        return new int[]{-1,-1};
    }

    /**
     * 暴力
     * @param nums
     * @param indexDifference
     * @param valueDifference
     * @return
     */
    public int[] findIndices1(int[] nums, int indexDifference, int valueDifference) {
        for(int i=0;i<nums.length;i++){
            for(int k=0;k<=i-indexDifference;k++){
                if(Math.abs(nums[i]-nums[k])>=valueDifference){
                    return new int[]{i,k};
                }
            }
        }
        return new int[]{-1,-1};
    }
}
