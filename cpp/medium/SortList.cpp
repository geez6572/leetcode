#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *sortList(ListNode *node) {
  if (node == nullptr || node->next == nullptr)
    return node;
  ListNode *fast = node;
  ListNode *slow = node;
  while (fast->next && fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  ListNode *right = sortList(slow->next);
  slow->next = nullptr;
  ListNode *left = sortList(node);
  // merge listnode
  ListNode *dummy = new ListNode();
  ListNode *last = dummy;
  while (left && right) {
    ListNode *temp;
    if (left->val < right->val) {
      temp = left;
      left = left->next;
    } else {
      temp = right;
      right = right->next;
    }
    temp->next = last->next;
    last->next = temp;
    last = last->next;
  }
  if (left)
    last->next = left;
  if (right)
    last->next = right;

  return dummy->next;
}

int main() {
  ListNode *node = new ListNode(4);
  node->next = new ListNode(2);
  node->next->next = new ListNode(1);
  node->next->next->next = new ListNode(3);
  ListNode *rs = sortList(node);
  while (rs) {
    std::cout << rs->val << " ";
  }
  return 0;
}
