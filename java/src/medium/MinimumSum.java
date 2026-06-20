package medium;


public class MinimumSum {
    public int minimumSum(int n, int k) {
        int sum=(1+Math.min(n,k/2))*Math.min(n,k/2)/2;
        sum+=(k+k+Math.max(n-k/2,0)-1)*Math.max(n-k/2,0)/2;
        return sum;
    }

    public static void main(String[] args) {
        MinimumSum minimumSum=new MinimumSum();
        minimumSum.minimumSum(5,4);
    }
}
