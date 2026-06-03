package medium;

public class BreakPalindrome {
    public String breakPalindrome(String palindrome) {
        if (palindrome.length() < 2) {
            return "";
        }
        char[] chars = palindrome.toCharArray();
        int index=0;
        while(index<chars.length&&chars[index]=='a'){
            index++;
        }
        if(index==chars.length){
            chars[index-1]='b';
        }else{
            chars[index]-=1;
        }
        return new String(chars);
    }
}
