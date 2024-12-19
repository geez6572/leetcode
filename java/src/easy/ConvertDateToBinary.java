package easy;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class ConvertDateToBinary {
    public String convertDateToBinary(String date) {
        String[] split = date.split("-");
        StringBuilder rs=new StringBuilder();
        for(int i=0;i<split.length;i++){
            rs.append(Integer.toBinaryString(Integer.parseInt(split[i]))+"-");
        }
        return rs.substring(0,rs.length()-1);
    }
}
