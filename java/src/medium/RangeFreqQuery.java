package medium;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class RangeFreqQuery {
    private HashMap<Integer, List<Integer>> map;

    public RangeFreqQuery(int[] arr) {
        map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (!map.containsKey(arr[i])) {
                map.put(arr[i], new ArrayList<>());
            }
            map.get(arr[i]).add(i);
        }
    }

    public int query(int left, int right, int value) {
        if (!map.containsKey(value)) {
            return 0;
        }
        List<Integer> arr = map.get(value);
        int l = -1;
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr.get(mid) < left) {
                l = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        int r = arr.size();
        start = 0;
        end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr.get(mid) > right) {
                r = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return r - l;
    }

    public static void main(String[] args) {
        int[] arr = {1, 1, 1, 2, 2};
        RangeFreqQuery rangeFreqQuery = new RangeFreqQuery(arr);
        rangeFreqQuery.query(0, 1, 2);
    }
}


