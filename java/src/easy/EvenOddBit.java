package easy;

public class EvenOddBit {
    public int[] evenOddBit(int n) {
        int odd=0;
        int even=0;
        for(int i=0;n>0;i++,n=n/2){
            if((n&1)==1){
                odd+=i%2;
                even+=(i+1)%2;
            }
        }
        return new int[]{odd,even};
    }
}
