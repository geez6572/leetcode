package medium;

public class CanBeValid {
    public boolean canBeValid(String s, String locked) {
        if (s.length() % 2 > 0) {
            return false;
        }
        int maxLeft = 0;
        int minLeft = 0;
        for (int i = 0; i < s.length(); i++) {
            if (locked.charAt(i) == '0') {
                maxLeft++;
                minLeft--;
            } else {
                maxLeft += s.charAt(i) == '(' ? 1 : -1;
                if (maxLeft < 0) {
                    return false;
                }
                minLeft += s.charAt(i) == '(' ? 1 : -1;
            }
            if (minLeft < 0) {
                minLeft = 1;
            }
        }
        return minLeft == 0;
    }
}

