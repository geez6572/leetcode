
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteDuplicates(ListNode *head) {
  ListNode *dummy = new ListNode();
  dummy->next = head;
  ListNode *pre = dummy;
  while (pre->next) {
    int flag = false;
    ListNode *cur = pre->next;
    while (cur->next && cur->next->val == cur->val) {
      ListNode *temp = cur->next;
      cur->next = temp->next;
      delete temp;
      flag = true;
    }
    if (flag) {
      pre->next = cur->next;
      delete cur;
    }
    pre = pre->next;
  }
  return dummy->next;
}

int main() { return 0; }
