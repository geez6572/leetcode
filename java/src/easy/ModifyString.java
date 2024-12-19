package easy;

public class ModifyString {
    public String modifyString(String s) {
        char[] chars = s.toCharArray();
        for(int i=0;i<chars.length;i++){
            if(chars[i]=='?'){
               char pre='a';
               if(i>0){
                   pre=chars[i-1];
               }
               char next=pre;
               if(i<chars.length-1&&chars[i+1]!='?'){
                   next=chars[i+1];
               }
               char rest1=(char)(Math.min(pre,next)+Math.abs(next-pre)/2);
               char rest2=(char) ('a'+((Math.max(pre,next)-'a'+(Math.min(pre,next)-'a'+'z'-Math.max(pre,next)+1)/2)%26));
               if(rest1!=pre&&rest1!=next){
                   chars[i]=rest1;
               }else{
                   chars[i]=rest2;
               }
            }
        }
        return new String(chars);
    }

    public static void main(String[] args) {
        ModifyString ms = new ModifyString();
        ms.modifyString("x?y");
    }
}
