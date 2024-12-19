package medium;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class ShortestDistanceAfterQueries {
    int bfs(boolean[][] map) {
        int rs = 0;
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[map.length];
        queue.offer(0);
        visited[0] = true;
        while (!queue.isEmpty()) {
            int len=queue.size();
            for(int k=0;k<len;k++) {
                int cur = queue.poll();
                if(cur==map.length-1){
                    return rs;
                }
                for (int i = 0; i < map.length; i++) {
                    if(!visited[i] && map[cur][i]) {
                        queue.offer(i);
                        visited[i] = true;
                    }
                }
            }
            rs++;
        }
        return rs;
    }

    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        boolean[][] map = new boolean[n][n];
        for (int i = 0; i < n - 1; i++) {
            map[i][i + 1] = true;
        }
        int [] ans = new int[queries.length];
        Arrays.fill(ans,n-1);
        for (int i = 0; i < queries.length; i++) {
            map[queries[i][0]][queries[i][1]] = true;
            ans[i]=Math.min(ans[i],bfs(map));
        }
        return ans;
    }

    public static void main(String[] args) {
      ShortestDistanceAfterQueries s = new ShortestDistanceAfterQueries();
      int [][] query={{2,4},{0,2},{0,4}};
      System.out.println(Arrays.toString(s.shortestDistanceAfterQueries(5, query)));
    }
}
