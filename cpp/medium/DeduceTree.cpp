#include "../dataStruct/BinaryTree.h"
#include <vector>
using namespace std;

TreeNode *recur(vector<int> &preorder, int ps, int pe, vector<int> &inorder,
                int is, int ie) {
  if (ps > pe || is > ie)
    return nullptr;
  int curVal = preorder[ps];
  TreeNode *cur = new TreeNode(curVal);
  int i = is;
  for (i = is; i <= ie; ++i) {
    if (inorder[i] == curVal)
      break;
  }
  int leftnodes = i - is;
  int rightnodes = ie - i;
  cur->left = recur(preorder, ps + 1, ps + leftnodes, inorder, is, i - 1);
  cur->right = recur(preorder, pe - rightnodes + 1, pe, inorder, i + 1, ie);
  return cur;
}

TreeNode *deduceTree(vector<int> &preorder, vector<int> &inorder) {
  return recur(preorder, 0, preorder.size() - 1, inorder, 0,
               inorder.size() - 1);
}
