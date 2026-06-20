package medium;

import java.util.*;

/**
 * @author: XueXinYu
 * @date: 9/14/25 8:17 PM
 * @description:
 */
public class Spellchecker {
    private static String getAl(String str){
        StringBuilder rs = new StringBuilder();
        for (char c : str.toCharArray()) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                rs.append('*');
            }else{
                rs.append(c);
            }
        }
        return rs.toString();
    }

    public String[] spellchecker(String[] wordlist, String[] queries) {
        // 构建map
        Set<String> eqSet = new HashSet<>();
        Map<String, String> caseMap = new HashMap<>();
        Map<String, String> alMap = new HashMap<>();
        for (String str : wordlist) {
            eqSet.add(str);
            String lowerCase = str.toLowerCase();
            caseMap.putIfAbsent(lowerCase,str);
            alMap.putIfAbsent(getAl(lowerCase),str);
        }

        String[] rs = new String[queries.length];
        for(int i = 0; i < queries.length; i++){
            if(eqSet.contains(queries[i])) {
                rs[i] = queries[i];
                continue;
            }
            String low = queries[i].toLowerCase();
            if(caseMap.containsKey(low)){
                rs[i] = caseMap.get(low);
            }else if(alMap.containsKey(getAl(low))){
                rs[i] = alMap.get(getAl(low));
            }else{
                rs[i] = "";
            }
        }
        return rs;
    }

    public static void main(String[] args) {
        String[] wordlist = new String[]{"ae","aa"};
        String[] queryList = new String[]{"UU"};
        new Spellchecker().spellchecker(wordlist, queryList);
    }
}
