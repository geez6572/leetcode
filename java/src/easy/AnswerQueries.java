package easy;

import java.util.Arrays;

public class AnswerQueries {

    private int lower_bound(int[]nums,int target){
        int left=0;
        int right=nums.length-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return left;
    }
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        for(int i=1;i<nums.length;i++) {
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<queries.length;i++) {
            int index=lower_bound(nums,queries[i]);
            if(index<nums.length&&nums[index]==queries[i]){
                index++;
            }
            queries[i]=index;
        }
        return queries;
    }

    public static void main(String[] args) {
        AnswerQueries answerQueries=new AnswerQueries();
        int[] nums=new int[]{4,5,2,1};
        int[] queries={3,10,21};
        int[] ints = answerQueries.answerQueries(nums, queries);
        for(int i:ints) {
            System.out.println(i);
        }
    }
}
