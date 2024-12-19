package easy;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class CountStudents {
    public int countStudents(int[] students, int[] sandwiches) {
        Queue<Integer> queue = new LinkedList<>();
        int[] counts=new int[2];
        for(int cur:students){
            if(cur==0){
                counts[0]++;
            }else{
                counts[1]++;
            }
            queue.add(cur);
        }
        int index=0;
        while(index<sandwiches.length){
            if(counts[sandwiches[index]]==0){
                break;
            }
            int cur=queue.poll();
            if(cur==sandwiches[index]){
                counts[cur]--;
                index++;
            }else{
                queue.add(cur);
            }
        }
        return counts[0]+counts[1];
    }
}
