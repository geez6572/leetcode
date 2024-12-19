package easy;

public class MaxScore {
    public int maxScore(String s) {
        int[] prefix=new int[s.length()+1];
        char[] chars=s.toCharArray();
        for(int i=0;i<chars.length;i++){
            prefix[i+1]=prefix[i];
            if(chars[i]=='1'){
                prefix[i+1]=prefix[i+1]+1;
            }
        }
        int rs=0;
        for(int i=1;i<prefix.length-1;i++){
            rs=Math.max(rs,(i-prefix[i]+prefix[prefix.length-1]-prefix[i]));
        }
        return rs;
    }
}
