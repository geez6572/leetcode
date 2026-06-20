package medium;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;


class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class NextLargerNodes {

    public int[] nextLargerNodes(ListNode head) {
        ArrayList<Integer> list = new ArrayList<>();
        while (head != null) {
            list.add(head.val);
            head = head.next;
        }
        int[] res = new int[list.size()];
        Stack<Integer> stack = new Stack<>();
        for (int i = list.size() - 1; i >= 0; i--) {
            int cur = list.get(i);
            while (!stack.isEmpty() && stack.peek() <= cur) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                res[i] = 0;
            } else {
                res[i] = stack.peek();
            }
            stack.push(cur);
        }
        return res;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        LinkedList<Integer> list = new LinkedList<>();
        head.next = new ListNode(7);
        head.next.next = new ListNode(9);
        int[] ints = new NextLargerNodes().nextLargerNodes(head);
        for(int i=0; i<ints.length; i++){
            System.out.println(ints[i]);
        }
    }
}
