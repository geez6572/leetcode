struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *rotateRight(ListNode *head, int k) {
  if (head == nullptr)
    return head;
  ListNode *travel = head;
  int len = 0;
  ListNode *last = nullptr;
  while (travel) {
    len++;
    if (travel->next == nullptr) {
      last = travel;
    }
    travel = travel->next;
  }
  k = k % len;
  if (k == 0)
    return head;
  last->next = head;
  for (int i = 0; i < len - k; ++i) {
    last = last->next;
  }
  head = last->next;
  last->next = nullptr;
  return head;
}
