package medium;

public class DistributeCandies {
    public long distributeCandies(int n, int limit) {
        if (n / 3 > limit) {
            return 0L;
        }
        int maxDis = Math.min(n, limit);
        long rs = 0;
        for (int i = 0; i <= maxDis; i++) {
            for (int k = 0; k <= n - i && k <= maxDis; k++) {
                if (n - i - k > maxDis)
                    continue;
                rs++;
            }
        }
        return rs;
    }

    public static void main(String[] args) {
        DistributeCandies distributeCandies = new DistributeCandies();
        System.out.println(distributeCandies.distributeCandies(5, 2));
    }
}
