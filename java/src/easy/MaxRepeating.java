package easy;

public class MaxRepeating {
    public int maxRepeating(String sequence, String word) {
        if(sequence.length()<word.length()){
            return 0;
        }
        int[] dp = new int[sequence.length()+1];
        int max=0;
        for (int i = word.length(); i < sequence.length(); i++) {
            if(sequence.substring(i-word.length(),i).equals(word)){
                dp[i]=dp[i-word.length()];
                max=dp[i]>max?dp[i]:max;
            }
        }
        return max;
    }

    public static void main(String[] args) {
        new MaxRepeating().maxRepeating("abba", "abba");
    }
}
