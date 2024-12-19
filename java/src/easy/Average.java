package easy;

public class Average {
    public double average(int[] salary) {
        int sum=0;
        int max=Integer.MIN_VALUE;
        int min=Integer.MAX_VALUE;
        for(int i=0;i<salary.length;i++) {
            sum+=salary[i];
            max=Math.max(max,salary[i]);
            min=Math.min(min,salary[i]);
        }
        return (sum-max-min)/(double)(salary.length-2);
    }
}
