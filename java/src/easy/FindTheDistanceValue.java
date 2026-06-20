package easy;

import java.util.Arrays;

public class FindTheDistanceValue {

    public int lower_bound(int target, int[] nums) {
       int left = 0;
       int right = nums.length - 1;
       while(left<=right){
           int mid = left + (right - left)/2;
           if(nums[mid]<target){
               left = mid + 1;
           }else{
               right = mid - 1;
           }
       }
       return left;
    }
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);
        int count = 0;
        for(int i=0;i<arr1.length;i++){
            int index=lower_bound(arr1[i],arr2);
            if((index<arr2.length&&arr2[index]-arr1[i]<=d)||(index>0&&arr1[i]-arr2[index-1]<=d)){
                continue;
            }
            count++;
        }
        return count;
    }
}
