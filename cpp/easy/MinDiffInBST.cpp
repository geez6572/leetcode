#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDiffInBST(TreeNode *root) {
  if (root == nullptr)
    return INT_MAX;
  int left = minDiffInBST(root->left);
  int right = minDiffInBST(root->right);
  int cur = INT_MAX;
  if (root->left) {
    TreeNode *left_node = root->left;
    while (left_node->right) {
      left_node = left_node->right;
    }
    cur = min(cur, root->val - left_node->val);
  }
  if (root->right) {
    TreeNode *right_node = root->right;
    while (right_node->left) {
      right_node = right_node->left;
    }
    cur = min(cur, right_node->val - root->val);
  }
  return min(min(left, right), cur);
}
