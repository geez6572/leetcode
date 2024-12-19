package easy;

public class CountNegatives {
    public int countNegatives(int[][] grid) {
        int x = 0, y = grid[0].length - 1;
        int rs = 0;
        while (y >= 0 && grid[x][y] < 0) {
            rs += grid.length;
            y--;
        }
        while (x < grid.length && y >= 0) {
            if (x + 1 < grid.length && grid[x + 1][y] >= 0) {
                x++;
            }else if(x+1>=grid.length){
                break;
            }else{
                y--;
                rs+=grid.length-x-1;
            }
        }
        return rs;
    }
}
