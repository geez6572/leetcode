package easy;

import java.util.HashSet;
import java.util.Set;

/**
 * @author: XueXinYu
 * @date: 9/15/25 9:32 PM
 * @description:
 */
public class CanBeTypedWords {
    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> set = new HashSet<>();
        for(char c : brokenLetters.toCharArray()) {
            set.add(c);
        }
        int broken = 0;
        int rs = 0;
        for(char c : text.toCharArray()) {
            if(c == ' '){
                broken = 0;
                if(broken>0){
                    rs++;
                }
                continue;
            }
            if(set.contains(c)){
                broken++;
            }
        }
        return rs;
    }
}
