#include "../dataStruct/ListNode.h"
#include <iostream>
#include <queue>

ListNode *reverse_list(ListNode *l) {
  ListNode *dummy = new ListNode();
  ListNode *temp;
  while (l) {
    temp = l->next;
    l->next = dummy->next;
    dummy->next = l;
    l = temp;
  }
  return dummy->next;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  reverse_list(l1);
  reverse_list(l2);
  ListNode *t1 = l1;
  while (t1) {
    std::cout << t1->val << " ";
    t1 = t1->next;
  }
  ListNode *rs = new ListNode();
  int flag = 0;
  while (l1 || l2) {
    int cur = flag;
    if (l1) {
      cur += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      cur += l2->val;
      l2 = l2->next;
    }
    ListNode *temp = new ListNode(cur % 10);
    temp->next = rs->next;
    rs->next = temp;
    flag = cur / 10;
  }
  return rs->next;
}

int main() {
  ListNode *node = new ListNode(7);
  node->next = new ListNode(2);
  node->next->next = new ListNode(4);
  node->next->next->next = new ListNode(3);

  ListNode *node1 = new ListNode(5);
  node1->next = new ListNode(6);
  node1->next->next = new ListNode(4);
  std::cout << addTwoNumbers(node, node1)->val;
  return 0;
}
