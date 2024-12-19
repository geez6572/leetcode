package easy;


public class SortString {
    public String sortString(String s) {
        int[] map=new int[26];
        int count=0;
        for(int i=0;i<s.length();i++){
            int cur=s.charAt(i)-'a';
            if(map[cur]==0){
                count++;
            }
            map[cur]++;
        }
        StringBuilder sb=new StringBuilder();
        while(count>0){
            for(int i=0;i<26;i++){
                if(map[i]>0){
                    sb.append((char)(i+'a'));
                    map[i]--;
                    if(map[i]==0){
                        count--;
                    }
                }
            }
            for(int i=25;i>=0;i--){
                if(map[i]>0){
                    sb.append((char)(i+'a'));
                    map[i]--;
                    if(map[i]==0){
                        count--;
                    }
                }
            }
        }
        return sb.toString();
    }
}
