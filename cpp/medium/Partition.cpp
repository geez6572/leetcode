#include "../dataStruct/ListNode.h"

ListNode *partition(ListNode *head, int x) {
  ListNode *dummy = new ListNode();
  dummy->next = head;
  head = dummy;
  while (dummy->next && dummy->next->val < x)
    dummy = dummy->next;
  ListNode *travel = dummy;
  while (travel->next) {
    if (travel->next->val < x) {
      ListNode *temp = travel->next;
      travel->next = temp->next;
      temp->next = dummy->next;
      dummy->next = temp;
      dummy = temp;
    } else {
      travel = travel->next;
    }
  }
  return head->next;
}
