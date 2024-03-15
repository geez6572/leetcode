struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

#include <queue>
using namespace std;

bool recursion(TreeNode *left, TreeNode *right) {
  if (left == nullptr && right == nullptr)
    return true;
  if (left == nullptr || right == nullptr || left->val != right->val)
    return false;
  bool l = recursion(left->left, right->left);
  if (!l)
    return false;
  bool r = recursion(left->right, right->right);
  return l && r;
}

bool checkSymmetricTree(TreeNode *root) {
  if (root == nullptr || (root->right == nullptr && root->left == nullptr)) {
    return true;
  }
  TreeNode *left = root->left;
  TreeNode *right = root->right;
  return recursion(left, right);
}
