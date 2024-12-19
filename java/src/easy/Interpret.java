package easy;

public class Interpret {
    public String interpret(String command) {
        StringBuilder result = new StringBuilder();
        int index = 0;
        while(index < command.length()) {
            if(command.charAt(index) == 'G') {
                result.append('G');
                index++;
            }else{
                int temp=index;
                while(command.charAt(temp)!=')'){
                    temp++;
                }
                if(temp-index==1){
                    result.append('o');
                }else{
                    result.append("al");
                }
                index=temp+1;
            }
        }
        return result.toString();
    }
}
