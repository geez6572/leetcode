package easy;

public class ArraySign {
    public int arraySign(int[] nums) {
        int count=0;
        for(int num:nums){
            if(num==0){
                return 0;
            }
            if(num<0){
                count++;
            }
        }
        return count%2==0?1:-1;
    }
}
