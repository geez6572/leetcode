#include <algorithm>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归版本122/124超时
int rob(TreeNode *root) {
  if (root == nullptr)
    return 0;
  int child = rob(root->right) + rob(root->left);
  int parent = root->val;
  if (root->left) {
    parent += rob(root->left->left);
    parent += rob(root->left->right);
  }
  if (root->right) {
    parent += rob(root->right->left);
    parent += rob(root->right->right);
  }
  return std::max(child, parent);
}

// 动态规划
void recursion(TreeNode *root) {
  if (root == nullptr)
    return;
  recursion(root->left);
  recursion(root->right);
  int parent = root->val;
  int child = 0;
  if (root->left) {
    child += root->left->val;
    if (root->left->left) {
      parent += root->left->left->val;
    }
    if (root->left->right) {
      parent += root->left->right->val;
    }
  }
  if (root->right) {
    child += root->right->val;
    if (root->right->left) {
      parent += root->right->left->val;
    }
    if (root->right->right) {
      parent += root->right->right->val;
    }
  }
}
int rob_dp(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  return root->val;
}
