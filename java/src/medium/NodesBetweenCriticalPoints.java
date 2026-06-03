package medium;

public class NodesBetweenCriticalPoints {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        if(head == null) return new int[]{-1,-1};
        int pre=head.val;
        int firstIndex=-1;
        int index=0;
        int preIndex=-1;
        int maxDistance=-1;
        int minDistance=Integer.MAX_VALUE;
        while(head!=null&&head.next!=null){
            int cur=head.val;
            int next=head.next.val;
            if((cur>pre&&cur>next)||(cur<pre&&cur<next)){
                if(firstIndex==-1){
                    firstIndex=index;
                }
                if(preIndex!=-1){
                    minDistance=Math.min(minDistance,index-preIndex);
                }
                preIndex=index;
            }
            pre=cur;
            index++;
            head=head.next;
        }
        maxDistance=preIndex-firstIndex;
        if(firstIndex==-1||preIndex-firstIndex==0){
            return new int[]{-1,-1};
        }
        return new int[]{minDistance,maxDistance};
    }
}
