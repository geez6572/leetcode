#include "../dataStruct/BinaryTree.h"
#include <algorithm>
#include <climits>

int minimum;
int second = -1;
void dfs(TreeNode *root) {
  if (root == nullptr)
    return;
  if (root->val > minimum && (root->val < second || second == -1))
    second = root->val;
  dfs(root->left);
  dfs(root->right);
}
int findSecondMinimumValue2(TreeNode *root) {
  minimum = root->val;
  dfs(root);
  return second;
}

int findSecondMinimumValue(TreeNode *root) {
  if (root->left == nullptr)
    return -1;
  if (root->left->val < root->right->val) {
    int left = findSecondMinimumValue(root->left);
    if (left == -1)
      return root->right->val;
    return std::min(left, root->right->val);
  } else if (root->left->val > root->right->val) {
    int right = findSecondMinimumValue(root->right);
    if (right == -1)
      return root->left->val;
    return std::min(right, root->left->val);
  } else {
    int left = findSecondMinimumValue(root->left);
    int right = findSecondMinimumValue(root->right);
    if (left == -1 && right == -1)
      return -1;
    if (left == -1)
      return right;
    if (right == -1)
      return left;
    return std::min(left, right);
  }
}
