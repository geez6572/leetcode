package easy;

import java.util.Arrays;

public class NowAndMaximumOnes {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int[] rs = new int[2];
        Arrays.fill(rs, 0);
        for (int i = 0; i < mat.length; i++) {
            int count =(int) Arrays.stream(mat[i]).count();
            if (count > rs[1]) {
                rs[0] = i;
                rs[1] = count;
            }
        }
        return rs;
    }
}
