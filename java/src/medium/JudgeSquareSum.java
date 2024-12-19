package medium;

import java.util.Collection;

public class JudgeSquareSum {
    boolean judgeSquareSum(int c) {
        int right=(int)Math.sqrt(c);
        for(int i=0;i<=right;i++){
            int cur=(int)Math.sqrt(c-i*i);
            if(cur*cur==c-i*i){
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        JudgeSquareSum judgeSquareSum = new JudgeSquareSum();
        System.out.println(judgeSquareSum.judgeSquareSum(5));
    }
}
