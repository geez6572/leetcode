package easy;

import java.util.Arrays;
import java.util.HashMap;

public class SimilarPairs {
    public int similarPairs(String[] words) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int rs=0;
        for(int i=0;i<words.length;i++){
            int m=0;
            for(int k=0;k<words[i].length();k++){
                m=m|(1<<(words[i].charAt(k)-'a'));
            }
            map.putIfAbsent(m,0);
            int pre=map.get(m);
            rs+=pre;
            map.put(m,pre+1);
        }
        return rs;
    }
}
