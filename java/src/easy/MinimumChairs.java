package easy;

public class MinimumChairs {
    static int findMinimumChairs(String s) {
        int count = 0;
        int max=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='E'){
                count++;
            }else{
                count--;
            }
            max=Math.max(max,count);
        }
        return max;
    }
}
