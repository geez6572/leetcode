package easy;

import java.util.Arrays;
import java.util.Collections;

public class SortPeople {
    public String[] sortPeople(String[] names, int[] heights) {
        for(int i=1;i<heights.length;i++){
            int cur=heights[i];
            String curName=names[i];
            int k=i-1;
            for(k=i-1;k>=0&&heights[k]<cur;k--){
                heights[k+1]=heights[k];
                names[k+1]=names[k];
            }
            heights[k+1]=cur;
            names[k+1]=curName;
        }
        return names;
    }
}
