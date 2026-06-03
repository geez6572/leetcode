package hard;

public class TextEditor {
    class Node {
        char c;
        Node next;
        Node prev;
        public Node(char c) {
            this.c = c;
        }
    }

    Node root;
    Node cursorPos;
    int length = 0;

    public TextEditor() {
        root = new Node(' ');
        cursorPos=root;
    }

    public void addText(String text) {
        for(char c: text.toCharArray()) {
            Node node=new Node(c);
            node.next=cursorPos.next;
            if(cursorPos.next!=null) cursorPos.next.prev=node;
            node.prev=cursorPos;
            cursorPos.next=node;
            cursorPos=node;
        }
    }
    public int deleteText(int k) {
        int count=0;
        while(cursorPos.prev!=null&&count<k){
            Node next=cursorPos.prev;
            next.next=cursorPos.next;
            if(cursorPos.next!=null) cursorPos.next.prev=next;
            cursorPos=next;
            count++;
        }
        return count;
    }

    public String cursorLeft(int k) {
        while(cursorPos.prev!=null&&k>0){
            cursorPos=cursorPos.prev;
            k--;
        }
        return getStr();
    }

    private String getStr(){
        Node temp=cursorPos;
        int count=0;
        StringBuilder str=new StringBuilder();
        while(temp.prev!=null&&count<10){
            str.insert(0,temp.c);
            count++;
            temp=temp.prev;
        }
        return str.toString();
    }
    public String cursorRight(int k) {
        while(cursorPos.next!=null&&k>0){
            cursorPos=cursorPos.next;
            k--;
        }
        return getStr();
    }
}
