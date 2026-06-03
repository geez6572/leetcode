package medium;

import java.util.HashMap;

public class BautifulSubarrays {
    public long beautifulSubarrays(int[] nums) {
        for(int i=1;i<nums.length;i++) {
            nums[i]=nums[i]^nums[i-1];
        }
        long ans=0;
        HashMap<Integer,Integer> map=new HashMap<>();
        map.put(0,1);
        for(int i=0;i<nums.length;i++) {
            Integer orDefault = map.getOrDefault(nums[i], 0);
            ans+=orDefault;
            map.put(nums[i],orDefault+ 1);
        }
        return ans;
    }

    public static void main(String[] args) {

        BautifulSubarrays b=new BautifulSubarrays();
        int [] nums={1,10,4};
        System.out.println(b.beautifulSubarrays(nums));
    }
}
