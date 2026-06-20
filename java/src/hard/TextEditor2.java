package hard;

import java.util.Stack;

// 对顶栈实现
public class TextEditor2 {
    StringBuilder left = new StringBuilder();
    StringBuilder right = new StringBuilder();

    public TextEditor2() {
    }

    public void addText(String text) {
        left.append(text);
    }

    public int deleteText(int k) {
        k= Math.min(k, left.length());
        left.setLength(left.length()-k);
        return k;
    }

    private void move(int k,StringBuilder src,StringBuilder dest) {
        while (!src.isEmpty() && k > 0) {
            dest.append(src.charAt(src.length()-1));
            src.setLength(src.length() - 1);
            k--;
        }
    }
    private String text(){
        if (left.length() <= 10) {
            return left.toString();
        }
        return left.substring(left.length() - 10, left.length());
    }
    public String cursorLeft(int k) {
        move(k,left,right);
        return text();
    }

    public String cursorRight(int k) {
        move(k,right,left);
        return text();
    }

    public static void main(String[] args) {
        StringBuilder str=new StringBuilder("abcdefghijklmn");
        str.substring(0,4);
        System.out.println(str.toString());
    }
}
