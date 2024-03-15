#include "../dataStruct/BinaryTree.h"

bool isSameTree(TreeNode *t1, TreeNode *t2) {
  if (t1 == nullptr && t2 == nullptr)
    return true;
  if (t1 == nullptr || t2 == nullptr || t1->val != t2->val)
    return false;
  return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot) {
  if (root == nullptr)
    return false;
  if (root->val == subRoot->val && isSameTree(root, subRoot)) {
    return true;
  }
  return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
