package easy;

public class MinimumRecolors {
    public int minimumRecolors(String blocks, int k) {
        int bCount=0;
        int rs=k;
        for(int i=0;i<blocks.length();i++){
            if(blocks.charAt(i)=='B'){
                bCount++;
            }
            if(i<k-1){
                continue;
            }
            rs=Math.min(rs,k-bCount);
            if(blocks.charAt(i-k+1)=='B'){
                bCount--;
            }
        }
        return rs;
    }
}
