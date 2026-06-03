package medium;

import java.util.LinkedList;

public class BrowserHistory {
    class Node{
        Node prev;
        Node next;
        String url;
        Node(String url){
            this.url = url;
        }
    }
    private Node cur;
    private String homepage;
    public BrowserHistory(String homepage) {
        cur = new Node(homepage);
        this.homepage = homepage;
    }

    public void visit(String url) {
        Node node = new Node(url);
        cur.next=node;
        node.prev=cur;
        cur=node;
    }

    public String back(int steps) {
        while(steps>0 && cur.url!=homepage) {
            cur=cur.prev;
            steps--;
        }
        return cur.url;
    }

    public String forward(int steps) {
        while(steps>0 && cur.next!=null) {
            cur=cur.next;
            steps--;
        }
        return cur.url;
    }
}
