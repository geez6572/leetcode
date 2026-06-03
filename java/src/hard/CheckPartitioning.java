package hard;

import java.util.Arrays;

public class CheckPartitioning {
    public boolean checkPartitioning(String s) {
        dfs=new int[s.length()][3];
        memo=new int[s.length()][s.length()];
        for(int i=0;i<s.length();i++){
            Arrays.fill(dfs[i],-1);
            Arrays.fill(memo[i],-1);
        }
        return checkPartitioning(s,3,0);
    }
    private int[][] dfs;
    private int[][] memo;
    private boolean isPart(String s,int start,int end){
        if(start>=end){
            return true;
        }
        if(memo[start][end]!=-1){
            return memo[start][end]==1?true:false;
        }
        boolean res=s.charAt(start)==s.charAt(end)&&isPart(s,start+1,end-1);
        memo[start][end]=res?1:0;
        return res;
    }
    private  boolean checkPartitioning(String s, int part,int start) {
        if(part==0||start==s.length()){
            return start==s.length()&&part==0;
        }
        if(dfs[start][part-1]!=-1){
            return dfs[start][part-1]==1?true:false;
        }

        for(int i=s.length()-1;i>=start;i--){
            if(isPart(s,start,i)&&checkPartitioning(s,part-1,i+1)){
                dfs[start][part-1]=1;
                return true;
            }
        }
        dfs[start][part-1]=0;
        return false;
    }

    public static void main(String[] args) {
        System.out.println(new CheckPartitioning().checkPartitioning("acab"));
    }
}
