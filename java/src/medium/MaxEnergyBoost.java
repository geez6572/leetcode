package medium;

public class MaxEnergyBoost {
    public long maxEnergyBoost(int[] energyDrinkA, int[] energyDrinkB) {
        long[][] dp=new long[energyDrinkA.length+1][2];
        dp[1][0]=energyDrinkA[0];
        dp[1][1]=energyDrinkB[0];
        for(int i=2;i<=energyDrinkA.length;i++){
            dp[i][0]=Math.max(dp[i-1][0],dp[i-2][1])+energyDrinkA[i-1];
            dp[i][1]=Math.max(dp[i-1][1],dp[i-2][0])+energyDrinkB[i-1];
        }
        long rs=0;
        for(int i=0;i<dp[0].length;i++){
            rs=Math.max(rs,dp[dp.length-1][i]);
        }
        return rs;
    }

    public static void main(String[] args) {
        int[] energyDrinkA=new int[]{3,1,1};
        int[] energyDrinkB=new int[]{1,1,3};
        MaxEnergyBoost maxEnergyBoost=new MaxEnergyBoost();
        long rs = maxEnergyBoost.maxEnergyBoost(energyDrinkA, energyDrinkB);
        System.out.println(rs);
    }
}
