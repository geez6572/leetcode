package medium;

import java.util.Arrays;

public class MaxScore {
    public int maxScore(int[] cardPoints, int k) {

        if(cardPoints.length==k){
            return Arrays.stream(cardPoints).sum();
        }
        int rs=0;
        int cur=0;
        int left=cardPoints.length-k;
        int right=left;
        int start=left;
        while(right!=0){
            cur+=cardPoints[right];
            right=(right+1)%cardPoints.length;
        }
        rs=cur;
        while(right<k){
            cur+=cardPoints[right++];
            cur-=cardPoints[left];
            left=(left+1)%cardPoints.length;
            rs=Math.max(rs,cur);
        }
        return rs;
    }

    public static void main(String[] args) {
        MaxScore ms = new MaxScore();
        int[] carPoints={1,2,3,4,5,6,1};
        System.out.println(ms.maxScore(carPoints, 3));
    }
}
