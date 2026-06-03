package medium;

import java.util.HashMap;

/**
 * @author: XueXinYu
 * @date: 7/6/25 11:07 AM
 * @description:
 */

public class FindSumPairs {
    private final int[] num1;
    private final int[] num2;
    private final HashMap<Integer, Integer> map = new HashMap<>();

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.num1 = nums1;
        this.num2 = nums2;
        for (int i = 0; i < num2.length; i++) {
            map.merge(nums2[i],1,Integer::sum);
        }
    }

    public void add(int index, int val) {
        map.merge(num2[index],-1,Integer::sum);
        num2[index] += val;
        map.merge(num2[index],1,Integer::sum);
    }

    public int count(int tot) {
        int count = 0;
        for (int i : num1) {
            count += map.getOrDefault(tot - i,0);
        }
        return count;
    }
}
