
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *trainingPlan(ListNode *head, int cnt) {
  ListNode *fast = head;
  while (cnt) {
    fast = fast->next;
    --cnt;
  }
  while (fast) {
    fast = fast->next;
    head = head->next;
  }
  return head;
}
