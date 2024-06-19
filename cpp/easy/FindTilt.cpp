#include "../dataStruct/BinaryTree.h"
#include <cstdlib>

int rs = 0;
int recur(TreeNode *node) {
  if (node == nullptr)
    return 0;
  int left = recur(node->left);
  int right = recur(node->right);
  rs += abs(left - right);
  return node->val + left + right;
}

int findTilt(TreeNode *root) {
  recur(root);
  return rs;
}
