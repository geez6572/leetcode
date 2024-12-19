package easy;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class SpecialArray {
    public static int specialArray(int[] nums) {
        Arrays.sort(nums);
        int pre=-1;
        int i=0;
        for(i=0; i<nums.length; i++) {
            if(nums[i]>nums.length-i){
                if(nums.length-i>Math.max(0,pre)){
                    return nums.length-i;
                }
                return -1;
            }else if(nums[i]==nums.length-i&&pre!=nums[i]){
                return nums[i];
            }
            pre=nums[i];
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] nums={3};
        Object o1=new Object();
        Object o2=new Object();
        System.out.println(o1.equals(o2));
        specialArray(nums);
    }
}
