package medium;

public class WateringPlants {
    public int wateringPlants(int[] plants, int capacity) {
        int curCap=capacity;
        int rs=0;
        for(int i=0;i<plants.length;i++){
            if(plants[i]<=curCap){
                curCap-=plants[i];
                rs++;
            }else{
                curCap=capacity-plants[i];
                rs+=i*2+1;
            }
        }
        return rs;
    }
}
