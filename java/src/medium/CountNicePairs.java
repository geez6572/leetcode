package medium;

import java.util.HashMap;

public class CountNicePairs {
    private final int mod=1000000007;
    private int rev(int x){
        int rs=0;
        while(x>0){
            rs=rs*10+x%10;
            x=x/10;
        }
        return rs;
    }
    public int countNicePairs(int[] nums) {
        HashMap<Integer,Integer> map=new HashMap<>();
        int rs=0;
        for(int cur:nums){
            int pair=cur-rev(cur);
            rs+=map.getOrDefault(pair,0);
            map.put(pair,map.getOrDefault(pair,0) + 1);
            rs=rs%mod;
        }
        return rs;
    }
}
