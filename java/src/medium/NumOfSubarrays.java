package medium;

public class NumOfSubarrays {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int sum=k*threshold;
        int cur=0;
        int rs=0;
        for(int i=0;i<arr.length;i++){
            cur+=arr[i];
            if(i<k-1){
                continue;
            }
            if(cur>=sum){
                rs++;
            }
            cur-=arr[i-k+1];
        }
        return rs;
    }
}
