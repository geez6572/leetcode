package medium;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class IsBipartite {
    private  int[] colors;
    private boolean valid;
    private int colorCount;
    public boolean isBipartite(int[][] graph) {
        int n=graph.length;
        colors=new int[n];
        colorCount=0;
        valid=true;
        for(int i=0;i<n;i++){
            if(colors[i]==0){
                dfs(graph,i,1);
            }
        }
        return valid;
    }

    private void dfs(int[][] graph,int node,int color){
        if(colors[node]!=0){
            return;
        }
        colors[node]=color;
        if(color==1){
            color=2;
        }else{
            color=1;
        }
        for(int i=0;i<graph[node].length;i++){
            if(colors[graph[node][i]]==0){
                dfs(graph,graph[node][i],color);
                if(valid==false){
                    return;
                }
            }else if(colors[graph[node][i]]!=color){
                valid=false;
                return;
            }
        }
    }

    public static void main(String[] args) {
        int[][] array = {
                {1},       // 第一个子数组，包含一个元素
                {0, 3},    // 第二个子数组，包含两个元素
                {3},       // 第三个子数组，包含一个元素
                {1, 2}     // 第四个子数组，包含两个元素
        };
        System.out.println(new IsBipartite().isBipartite(array));
    }
}
