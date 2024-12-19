package easy;

import java.util.HashMap;
import java.util.HashSet;

public class MaximumNumberOfStringPairs {
    public int maximumNumberOfStringPairs(String[] words) {
        HashSet<String> set = new HashSet<>();
        int rs=0;
        for(String word : words){
            String rev=new StringBuilder(word).reverse().toString();
            if(set.contains(rev)){
                rs++;
            }
            set.add(word);
        }
        return rs;
    }
}
