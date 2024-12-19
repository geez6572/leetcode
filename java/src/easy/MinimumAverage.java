package easy;

import java.util.*;

public class MinimumAverage {
	public double minimumAverage(int[] nums) { 	
		Arrays.sort(nums);
		int left=0;
		int right=nums.length-1;
		double rs=Integer.MAX_VALUE;
		while(left<right) {
			double cur= (double) (nums[left] + nums[right]) /2;
			rs=Math.min(rs, cur);
			left++;
			right--;
		}
		return rs;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TreeSet<Integer> set=new TreeSet<>();
		set.add(99);
		set.add(22);
		set.add(33);
		System.out.println(set);
		LinkedHashSet<Integer> set1=new LinkedHashSet<>();
		set1.add(99);
		set1.add(22);
		set1.add(33);
		System.out.println(set1);
		LinkedHashMap<Integer,String> map1=new LinkedHashMap<>();
		map1.put(99,"A");
		map1.put(22,"B");
		map1.put(33,"C");
		System.out.println(map1);
	}

}
