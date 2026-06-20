package medium;


public class MinimumCost {

    public long minimumCost(String s) {
        char[] chars=s.toCharArray();
        long rs=0;
        for(int i=1;i<chars.length;i++){
            if(chars[i]!=chars[i-1]){
                rs+=Math.min(i,chars.length-i);
            }
        }
        return  rs;
    }
}
