package easy;

public class GetSmallestString {
    public String getSmallestString(String s) {
        char[] chars = s.toCharArray();
        for(int i=0;i<chars.length-1;i++){
            if((chars[i]&1)==(chars[i+1]&1)&&chars[i]>chars[i+1]){
                char temp = chars[i];
                chars[i]=chars[i+1];
                chars[i+1]=temp;
            }
        }
        return new String(chars);
    }
}
