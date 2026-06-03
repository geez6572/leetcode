package medium;

import java.util.ArrayList;

public class BrowserHistory2 {
    ArrayList<String> history = new ArrayList<>();
    private int curIndex;
    private int curlen;
    public BrowserHistory2(String homepage) {
        history.add(homepage);
        curIndex = 0;
        curlen = 1;
    }

    public void visit(String url) {
        curIndex++;
        if(curIndex<history.size()) {
            history.set(curIndex, url);
        }else{
            history.add(url);
        }
        curlen=curIndex+1;
    }

    public String back(int steps) {
        if(steps>curIndex) {
            curIndex=0;
        }else{
            curIndex-=steps;
        }
        return history.get(curIndex);
    }

    public String forward(int steps) {
        if(curIndex+steps>=curlen) {
            curIndex=curlen-1;
        }else{
            curIndex+=steps;
        }
        return history.get(curIndex);
    }
}
