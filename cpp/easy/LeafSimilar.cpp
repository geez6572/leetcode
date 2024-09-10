#include "../dataStruct/BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;
void recursion(TreeNode *root, vector<int> &seq) {
  if (root == nullptr) {
    return;
  }
  if (root->left == nullptr && root->right) {
    seq.push_back(root->val);
  }
  recursion(root->left, seq);
  recursion(root->right, seq);
}
bool leafSimilar(TreeNode *root1, TreeNode *root2) {
  vector<int> seq1;
  vector<int> seq2;
  recursion(root1, seq1);
  recursion(root2, seq2);
  if (seq1.size() != seq2.size())
    return false;
  for (int i = 0; i < seq1.size(); ++i) {
    if (seq1[i] != seq2[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(3);
  root2->right = new TreeNode(2);
  cout << leafSimilar(root1, root2);
  return 0;
}
