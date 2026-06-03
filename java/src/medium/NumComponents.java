package medium;

public class NumComponents {
    public int numComponents(ListNode head, int[] nums) {
        boolean[]map=new boolean[10000];
        for(int i=0;i<nums.length;i++){
            map[nums[i]]=true;
        }
        int rs=0;
        boolean flag=false;
        while(head!=null){
            if(!map[head.val]&&flag){
                rs++;
                flag=false;
            }else{
                flag=true;
            }
            head=head.next;
        }
        return rs+(flag?1:0);
    }
}
