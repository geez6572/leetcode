package medium;

public class AddSpaces {
    public String addSpaces(String s, int[] spaces) {
        int sIndex=0;
        int spaceIndex=0;
        StringBuilder sb=new StringBuilder();
        while (sIndex<s.length()){
            if(spaceIndex<spaces.length&&sIndex==spaces[spaceIndex]){
                sb.append(" ");
                spaceIndex++;
            }else{
                sb.append(s.charAt(sIndex));
                sIndex++;
            }
        }
        return sb.toString();
    }
}
