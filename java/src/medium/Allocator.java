package medium;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Allocator {

    private boolean[] mem;
    class Node{
        int start, end;
        public Node(int start, int end){
            this.start = start;
            this.end = end;
        }
    }
    private HashMap<Integer, ArrayList<Node>> allocated;
    private int hasMem(int size){
        int count = 0;
        for(int i = 0; i < mem.length; i++){
            if(!mem[i]){
                count++;
            }else{
                count=0;
            }
            if(count == size){
                return i-size+1;
            }
        }
        return -1;
    }
    public Allocator(int n) {
        mem = new boolean[n];
        allocated = new HashMap<>();
    }

    public int allocate(int size, int mID) {
        int start=hasMem(size);
        if(start == -1){
            return -1;
        }
        int end=start+size-1;
        Arrays.fill(mem,start,end+1,true);
        if(!allocated.containsKey(mID)){
            allocated.put(mID,new ArrayList<>());
        }
        allocated.get(mID).add(new Node(start,end));
        return start;
    }

    public int freeMemory(int mID) {
        if(!allocated.containsKey(mID)){
            return -1;
        }

        ArrayList<Node> nodes = allocated.get(mID);
        int size=0;
        for(Node node : nodes){
            Arrays.fill(mem,node.start,node.end+1,false);
            size+=node.end-node.start+1;
        }
        allocated.remove(mID);
        return size;
    }


}