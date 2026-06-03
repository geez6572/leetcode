package medium;

import java.util.Arrays;

public class SplitListToParts {
    public ListNode[] splitListToParts(ListNode head, int k) {
        int len=0;
        ListNode travel = head;
        while(travel!=null){
            len++;
            travel = travel.next;
        }
        int avg=len/k;
        int remain=len%k;
        ListNode[] rs=new ListNode[k];
        Arrays.fill(rs,null);
        int cur=0;
        ListNode dummy=new ListNode(0);
        dummy.next = head;
        while(dummy.next!=null){
            ListNode next=dummy;
            for(int i=0;i<avg+(remain>0?1:0);i++){
                next=next.next;
            }
            remain--;
            rs[cur++]=dummy.next;
            dummy.next=next.next;
            next.next=null;
        }
        return rs;
    }

    public static void main(String[] args) {
        ListNode head=new ListNode(1);
        head.next=new ListNode(2);
        head.next.next=new ListNode(3);
        SplitListToParts splitListToParts = new SplitListToParts();
        splitListToParts.splitListToParts(head, 5);
    }
}
