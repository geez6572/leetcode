package easy;

import java.util.*;

public class OrderedStream {
    private String[] list;
    private  int cur;

    public OrderedStream(int n) {
        list = new String[n];
        cur = 0;
    }

    public List<String> insert(int idKey, String value) {
        list[idKey - 1]= value;
        List<String> rs = new ArrayList<>();
        for (; cur < list.length; cur++) {
            if (list[cur] == null||list[cur] == "") {
                break;
            }
            rs.add(list[cur]);
            list[cur]= null;
        }
        return rs;
    }
}
