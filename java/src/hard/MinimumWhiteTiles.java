package hard;

import java.util.Arrays;

public class MinimumWhiteTiles {
    public int minimumWhiteTiles(String floor, int numCarpets, int carpetLen) {
        int n=floor.length();
        int[][] memo=new int[numCarpets+1][n];
        for(int[] row:memo){
            Arrays.fill(row,-1);
        }
        return dfs(numCarpets,n-1,floor.toCharArray(),memo,carpetLen);
    }
    public int dfs(int numCarpets,int lastFloor,char[] floor,int[][]memo,int carpetLen){
        if(numCarpets*carpetLen>lastFloor){
            return 0;
        }
        if(memo[numCarpets][lastFloor]!=-1){
            return memo[numCarpets][lastFloor];
        }
        int rs=dfs(numCarpets,lastFloor-1,floor,memo,carpetLen)+floor[lastFloor]-'0';
        if(numCarpets>0){
            rs=Math.min(rs,dfs(numCarpets-1,lastFloor-carpetLen,floor,memo,carpetLen));
        }
        memo[numCarpets][lastFloor] = rs;
        return rs;
    }


    public int minimumWhiteTiles_dp(String floor, int numCarpets, int carpetLen) {
        int n=floor.length();
        int[][] dp=new int[numCarpets+1][n];
        return 0;

    }
}
