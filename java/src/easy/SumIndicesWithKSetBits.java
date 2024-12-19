package easy;

import java.sql.Statement;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;
import java.util.zip.CheckedOutputStream;

public class SumIndicesWithKSetBits {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        if(k==0){
            return nums.getFirst();
        }
        int rs=0;
        for(int i=0;i<nums.size();i++){
            int cur=i;
            int count=0;
            while(cur>0){
                count=cur&1;
                cur=cur>>1;
            }
            if(count==k){
                rs+=nums.get(i);
            }
        }
        return rs;
    }

    public static void main(String[] args) {
        List<Integer> list=Arrays.asList(5,10,1,5,2);
        SumIndicesWithKSetBits sumIndicesWithKSetBits = new SumIndicesWithKSetBits();
        sumIndicesWithKSetBits.sumIndicesWithKSetBits(list, 1);
    }
}
