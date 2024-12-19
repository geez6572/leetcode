package easy;

import java.util.ArrayList;
import java.util.List;

public class Reformat {
    public String reformat(String s) {
        List<Character> nums = new ArrayList<>();
        List<Character> alpha = new ArrayList<>();
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i)>='a'&&s.charAt(i)<='z') {
                alpha.add(s.charAt(i));
            }else{
                nums.add(s.charAt(i));
            }
        }
        if(Math.abs(nums.size()-alpha.size())>1){
            return "";
        }
        char[] res=new char[s.length()];
        int ai=0;
        int ni=0;
        boolean flag=nums.size()>alpha.size();
        for(int i=0;i<res.length;i++) {
            if(flag) {
                res[i]=nums.get(ni);
                ni++;
            }else{
                res[i]=alpha.get(ai);
                ai++;
            }
            flag=!flag;
        }
        return new String(res);
    }

    public static void main(String[] args) {

    }
}
