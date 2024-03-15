struct ListNode {
  int val;
  ListNode *next;
  ListNode(int a) : val(a), next(nullptr){};
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  int a_len = 0;
  int b_len = 0;
  ListNode *a_temp = headA;
  ListNode *b_temp = headB;
  while (a_temp || b_temp) {
    if (a_temp) {
      a_temp = a_temp->next;
      a_len++;
    }
    if (b_temp) {
      b_temp = b_temp->next;
      b_len++;
    }
  }
  if (a_len > b_len) {
    for (int i = 0; i < a_len - b_len; ++i) {
      headA = headA->next;
    }
  } else {
    for (int i = 0; i < b_len - a_len; ++i) {
      headB = headB->next;
    }
  }
  while (headA) {
    if (headA == headB)
      return headA;
    headA = headA->next;
    headB = headB->next;
  }
  return nullptr;
}
