package medium;

import java.util.concurrent.locks.Lock;

public class HIndex {
    public int hIndex(int[] citations) {
        int left=0;
        int right=citations.length-1;
        int rs=0;
        while(left<right){
            int mid=(left+right)/2;
            if(citations[mid]==citations.length-mid){
                rs=citations[mid];
                break;
            }else if(citations[mid]<citations.length-mid){
                left=mid+1;
            }else{
                rs=Math.max(rs,citations.length-mid);
                right=mid-1;
            }
        }
        return rs;
    }
}
