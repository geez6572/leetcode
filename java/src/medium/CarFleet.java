package medium;

import java.util.Arrays;

public class CarFleet {
    public int carFleet(int target, int[] position, int[] speed) {
        Integer[] indicate = new Integer[position.length];
        for (int i = 0; i < position.length; i++) {
            indicate[i] = i;
        }
        Arrays.sort(indicate, (a, b) -> Integer.compare(position[a], position[b]));
        int rs=1;
        for (int i = 0; i < position.length-1; i++) {
            double time1=(double) (target-position[indicate[i]])/speed[indicate[i]];
            double time2=(double) (target-position[indicate[i+1]])/speed[indicate[i+1]];
            if(time1<time2){
                rs++;
            }
        }
        return rs;
    }

    public static void main(String[] args) {
        CarFleet cf = new CarFleet();
        System.out.println(cf.carFleet(12, new int[]{0,2,4}, new int[]{2,1,3}));
    }
}
