package medium;

import java.util.*;


public class Checkout {
    Queue<Integer> queue;
    Deque<Integer> deque;
    public Checkout() {
        queue = new LinkedList<>();
        deque = new LinkedList<>();
    }

    public int get_max() {
        if(deque.isEmpty()){
            return -1;
        }
        return deque.getFirst();
    }

    public void add(int value) {
        while(!deque.isEmpty()&&value>deque.getLast()){
            deque.removeLast();
        }
        deque.addLast(value);
        queue.add(value);
    }

    public int remove() {
        if(deque.isEmpty()){
            return -1;
        }
        int top=queue.remove();
        if(top==deque.getFirst()){
            deque.removeFirst();
        }
        return top;
    }
}