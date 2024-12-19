package easy;

public class MaxHeightOfTriangle {
	public static int calculate(int red,int blue,boolean priority) {
		int countRed=red;
		int countBlue=blue;
		int cur=1;
		boolean reded=priority;
		while(countRed>0&&countBlue>0){
			if(reded) {
				countRed-=cur;
			}else {
				countBlue-=cur;
			}
			if(countBlue<0||countRed<0) {
				break;
			}
			cur++;
			reded=!reded;
		}
		return cur-1;
	}
	public static int maxHeightOfTriangle(int red, int blue) {
		return Math.max(calculate(red, blue, false), calculate(red, blue, true));
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int rs=maxHeightOfTriangle(2, 4);
		System.out.println(rs);
	}

}
