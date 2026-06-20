package medium;

import java.lang.reflect.Array;
import java.util.Arrays;

public class GameOfLife {
    private int [][] next={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1,},{1,0},{1,1}};
    private int getAlive(int[][] board, int row, int col) {
        int count=0;
        for(int i=0;i<next.length;i++){
            int nextRow=row+next[i][0];
            int nextCol=col+next[i][1];
            if(nextRow<board.length&&nextRow>=0 &&nextCol>=0&& nextCol<board[0].length && board[nextRow][nextCol]%8==1){
                count++;
            }
        }
        return count;
    }
    public void gameOfLife(int[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                int alive = getAlive(board, i, j);
                board[i][j] += alive*8;
            }
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if(board[i][j]/8<=1||board[i][j]/8>3){
                    board[i][j]=0;
                }else if (board[i][j]%8==0&&board[i][j]/8==3){
                    board[i][j]=1;
                }else{
                    board[i][j]=board[i][j]%8;
                }
            }
        }
    }

    public static void main(String[] args) {
    }
}
