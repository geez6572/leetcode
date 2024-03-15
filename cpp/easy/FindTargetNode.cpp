#include "../dataStruct/BinaryTree.h"

int rs = -1;
void travel(TreeNode *root, int *cnt) {
  if (root->right)
    travel(root->right, cnt);
  (*cnt)--;
  if (*cnt == 0) {
    rs = root->val;
    return;
  }
  if (root->left)
    travel(root->left, cnt);
}

int findTargetNode(TreeNode *root, int cnt) {
  travel(root, &cnt);
  return rs;
}
