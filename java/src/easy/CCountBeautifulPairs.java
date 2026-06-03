package easy;

public class CCountBeautifulPairs {

    private int getFirst(int x){
        while(x>=10){
            x=x/10;
        }
        return x;
    }
    private int getLast(int x){
        return x%10;
    }
    private boolean satisfy(int x,int y){
        for(int i=2;i<=Math.min(x,y);i++){
            if(x%i==0 && y%i==0){
                return false;
            }
        }
        return true;
    }
    public int countBeautifulPairs(int[] nums) {
        int[] map=new int[10];
        int rs=0;
        for(int cur:nums){
            int first = getFirst(cur);
            int last = getLast(cur);
            for(int k=0;k<10;k++){
                if(satisfy(last,k)){
                    rs++;
                }
            }
            map[first]++;
        }
        return rs;
    }
}
