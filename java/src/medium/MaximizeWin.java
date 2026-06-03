package medium;

import java.util.Arrays;

public class MaximizeWin {
    public int maximizeWin(int[] prizePositions, int k) {
        if(prizePositions[prizePositions.length-1]-prizePositions[0]<=2*k){
            return (int)Arrays.stream(prizePositions).count();
        }

        int left=0;
        int mid=left;
        while(prizePositions[mid]-prizePositions[0]<=k){
            mid++;
        }
        int preMax=mid;
        int right=mid;
        while(prizePositions[right]-prizePositions[mid]<=k){
            right++;
        }
        int rs=right;
        while (right<prizePositions.length){
            while(prizePositions[mid]-prizePositions[left]>k){
                left++;
            }
            while(prizePositions[right]-prizePositions[mid]>k){
                mid++;
            }
            while(right<prizePositions.length&&prizePositions[right]-prizePositions[mid]<=k){
                right++;
            }
            rs=Math.max(rs,right-mid+preMax);
            preMax=Math.max(mid-left,preMax);
        }
        rs=Math.max(rs,right-mid+preMax);
        return rs;
    }
}
