package easy;

public class IosingPlayer {
    public String losingPlayer(int x, int y) {
        y=y/4;
        int rs=Math.min(x, y);
        return rs%2==0?"Bob":"Alice";
    }
}
