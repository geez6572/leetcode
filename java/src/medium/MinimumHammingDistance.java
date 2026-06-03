package medium;

import struct.UnionFind;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MinimumHammingDistance {
    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        UnionFind uf = new UnionFind(source.length);
        for (int[] allowedSwap : allowedSwaps) {
            uf.join(allowedSwap[0],allowedSwap[1]);
        }

        Map<Integer, List<Integer>> valueToIndex = new HashMap<>();
        for(int i = 0;i<target.length;i++){
            valueToIndex.put(source[i],i);
        }

        int rs = target.length;
        for(int i = 0;i<target.length;i++){
            if(source[i] == target[i]){
                rs--;
                continue;
            }

            Integer ta = valueToIndex.get(target[i]);
            if(ta == null){
                continue;
            }
            if(uf.isSame(i,ta)){
                rs--;
            }
        }
        return rs;
    }

    public static void main(String[] args) {
        int[] source = {1,2,3,4};
        int[] target = {2,1,4,5};
        int[][] allow = {{0,1},{2,3}};
        MinimumHammingDistance minimumHammingDistance = new MinimumHammingDistance();
        System.out.println(minimumHammingDistance.minimumHammingDistance(source,target,allow));
    }
}
