struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right) {
  if (left >= right)
    return head;
  ListNode *guard = new ListNode();
  guard->next = head;
  head = guard;
  for (int i = 1; i < left; ++i) {
    guard = guard->next;
  }
  ListNode *last = guard->next;
  ListNode *travel = guard->next;
  guard->next = nullptr;
  for (int i = 0; i <= right - left; ++i) {
    ListNode *temp = travel->next;
    travel->next = guard->next;
    guard->next = travel;
    travel = temp;
  }
  last->next = travel;
  return head;
}
