package medium;

public class MaximumTripletValue {
    public long maximumTripletValue(int[] nums) {
        long ans=0;
        int preMax=0;
        int preDiff=0;
        for(int cur:nums){
            ans=Math.max(ans,preDiff*cur);
            preDiff=Math.max(preDiff,preMax-cur);
            preMax=Math.max(preMax,cur);
        }
        return ans;
    }
}
