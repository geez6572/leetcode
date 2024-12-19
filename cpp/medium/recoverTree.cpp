#include "../dataStruct/BinaryTree.h"
#include <vector>
using namespace std;

TreeNode *check_valid(TreeNode *node, int parent, bool greater) {
  if (node == nullptr) {
    return node;
  }
  if (greater && node->val < parent) {
    return node;
  }
  if (!greater && node->val > parent) {
    return node;
  }
  TreeNode *left = check_valid(node->left, node->val, false);
  TreeNode *right = check_valid(node->right, node->val, true);
  if (left && right) {
    int temp = left->val;
    left->val = right->val;
    right->val = temp;
    return nullptr;
  }
  return nullptr;
}
void recoverTree(TreeNode *root) {
  vector<TreeNode *> stack;
  TreeNode *pre = nullptr;
  TreeNode *x = nullptr;
  TreeNode *y = nullptr;
  while (root || !stack.empty()) {
    if (root) {
      stack.push_back(root);
      root = root->left;
    } else {
      root = stack.back();
      stack.pop_back();
      if (pre != nullptr && pre->val > root->val) {
        y = root;
        if (x == nullptr) {
          x = pre;
        } else {
          break;
        }
      }
      pre = root;
      root = root->right;
    }
  }
  int temp = x->val;
  x->val = y->val;
  y->val = temp;
}
