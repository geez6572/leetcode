package medium;

public class MatrixScore {
    public int matrixScore(int[][] grid) {
        for(int i=0;i<grid.length;i++){
            if(grid[i][0]==0){
                for(int j=0;j<grid[0].length;j++){
                    grid[i][j]=grid[i][j]^1;
                }
            }
        }
        for(int i=0;i<grid[0].length;i++){
            int count=0;
            for(int j=0;j<grid.length;j++){
                count+=grid[j][i];
            }
            if(count<(grid.length+1)/2){
                for(int j=0;j<grid.length;j++){
                    grid[i][j]=grid[i][j]^1;
                }
            }
        }
        int rs=0;
        for(int i=0;i<grid.length;i++){
            int cur=0;
            for(int j=0;j<grid[0].length;j++){
                cur=cur*2+grid[i][j];
            }
            rs+=cur;
        }
        return rs;
    }
}
