package medium;

import java.util.*;

public class MaxDistance {
  public int maxDistance(List<List<Integer>> arrays) {
    Deque<List<Integer>> max = new LinkedList<>();
    Deque<List<Integer>> min = new LinkedList<>();
    for (int i = 0; i < arrays.size(); i++) {
      int last = arrays.get(i).get(arrays.get(i).size() - 1);
      int first = arrays.get(i).get(0);
      if (max.isEmpty() || max.peekLast().get(0) < last) {
        max.addLast(new ArrayList<>(Arrays.asList(last, i)));
        if (max.size() > 2) {
          max.removeFirst();
        }
      } else if (max.size() == 1 || last > max.peekFirst().get(0)) {
        if (max.size() > 1) {
          max.removeFirst();
        }
        max.addFirst(new ArrayList<>(Arrays.asList(last, i)));
      }
      if (min.isEmpty() || min.peekLast().get(0) > first) {
        min.addLast(new ArrayList<>(Arrays.asList(first, i)));
        if (min.size() > 2) {
          min.removeFirst();
        }
      } else if (min.size() == 1 || first < min.peekFirst().get(0)) {
        if (min.size() > 1) {
          min.removeFirst();
        }
        min.addFirst(new ArrayList<>(Arrays.asList(first, i)));
      }
    }

    if (max.peekLast().get(1) != min.peekLast().get(1)) {
      return max.peekLast().get(0) - min.peekLast().get(0);
    }
    return Math.max(
        max.peekLast().get(0) - min.peekFirst().get(0),
        max.peekFirst().get(0) - min.peekLast().get(0));
  }

  public static void main(String[] args) {
    List<List<Integer>> list = new ArrayList<>();
    list.add(Arrays.asList(-1, 5));
    list.add(Arrays.asList(1, 4, 6));
    list.add(Arrays.asList(4, 5, 6));
    System.out.println(new MaxDistance().maxDistance(list));
  }
}
