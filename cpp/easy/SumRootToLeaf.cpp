#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sum = 0;
void recursion(TreeNode *root, int cur_val) {
  int next = (cur_val << 2) + root->val;
  if (root->left == nullptr && root->right == nullptr) {
    sum += next;
  }

  if (root->left) {
    recursion(root->left, next);
  }
  if (root->right) {
    recursion(root->right, next);
  }
}

int sumRootToLeaf(TreeNode *root) {
  recursion(root, 0);
  return sum;
}

int main() {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(0);
  TreeNode *right = new TreeNode(1);
  left->left = new TreeNode(0);
  left->right = new TreeNode(1);
  right->left = new TreeNode(0);
  right->right = new TreeNode(1);
  root->left = left;
  root->right = right;
  cout << sumRootToLeaf(root);
  return 0;
}
