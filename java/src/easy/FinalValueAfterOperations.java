package easy;

public class FinalValueAfterOperations {
    public int finalValueAfterOperations(String[] operations) {
        int initial = 0;
        for (int i = 0; i < operations.length; i++) {
            if (operations[i].charAt(1) == '-') {
                initial--;
            } else {
                initial++;
            }
        }
        return initial;
    }
}
