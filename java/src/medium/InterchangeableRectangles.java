package medium;

import java.util.HashMap;

public class InterchangeableRectangles {
    public long interchangeableRectangles(int[][] rectangles) {
        HashMap<Double,Integer> map = new HashMap<>();
        long rs=0;
        for(int[] rectangle : rectangles) {
            double ratio=(double)rectangle[0]/rectangle[1];
            int exist=map.getOrDefault(ratio,0);
            map.put(ratio,exist+1);
            rs+=exist;
        }
        return rs;
    }

    public static void main(String[] args) {
        InterchangeableRectangles interchangeableRectangles = new InterchangeableRectangles();
        int[][] rectangles = {{4,8},{3,6},{10,20},{15,30}};
        System.out.println(interchangeableRectangles.interchangeableRectangles(rectangles));
    }
}
