package medium;

public class MaxSumTwoNoOverlap {
    private int maxSum(int[]nums,int firstLen,int secondLen){
        int preMax=0;
        for(int i=0;i<firstLen;i++){
            preMax+=nums[i];
        }
        int firstCur=preMax;
        int rs=0;
        int secondCur=0;
        int mid=firstLen;
        for(int i=mid;i<nums.length;i++){
            if(i<firstLen+secondLen){
                secondCur+=nums[i];
                continue;
            }
            rs=Math.max(rs,preMax+secondCur);
            firstCur=firstCur-nums[mid-firstLen]+nums[mid];
            secondCur=secondCur-nums[mid]+nums[i];
            preMax=Math.max(preMax,firstCur);
            mid++;
        }
        rs=Math.max(rs,preMax+secondCur);
        return rs;
    }
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        return Math.max(maxSum(nums,firstLen,secondLen),maxSum(nums,secondLen,firstLen));
    }

    public static void main(String[] args) {
        int[] nums={0,6,5,2,2,5,1,9,4};
        System.out.println(new MaxSumTwoNoOverlap().maxSumTwoNoOverlap(nums,1,2));
    }
}
