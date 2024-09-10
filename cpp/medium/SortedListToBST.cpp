#include "../dataStruct/BinaryTree.h"
#include "../dataStruct/ListNode.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;
TreeNode *construct(vector<int> &vec, int left, int right) {
  if (left > right)
    return nullptr;
  int mid = left + (right - left) / 2;
  TreeNode *cur = new TreeNode(vec[mid]);
  cur->left = construct(vec, left, mid - 1);
  cur->right = construct(vec, mid + 1, right);
  return cur;
}

TreeNode *sortedListToBST(ListNode *head) {
  vector<int> vec;
  while (head) {
    vec.push_back(head->val);
    head = head->next;
  }
  return construct(vec, 0, vec.size() - 1);
}

void travel(TreeNode *node) {
  if (node == nullptr)
    return;
  travel(node->left);
  cout << node->val << " ";
  travel(node->right);
}

int main() {
  ListNode *root = new ListNode(-10);
  root->next = new ListNode(-3);
  root->next->next = new ListNode(0);
  root->next->next->next = new ListNode(5);
  root->next->next->next->next = new ListNode(9);
  TreeNode *rs = sortedListToBST(root);
  travel(rs);
  return 0;
}
