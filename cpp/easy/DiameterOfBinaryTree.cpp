#include "../dataStruct/BinaryTree.h"

int count_depth(TreeNode *root, int *rs) {
  if (root == nullptr)
    return 0;
  int left_depth = count_depth(root->left, rs);
  int right_depth = count_depth(root->right, rs);
  int cur_depth = 0;
  if (left_depth)
    cur_depth += left_depth;
  if (right_depth)
    cur_depth += right_depth;
  if (cur_depth > *rs)
    *rs = cur_depth;
  return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}
int diameterOfBinaryTree(TreeNode *root) {
  int rs = -1;
  count_depth(root, &rs);
  return rs;
}
