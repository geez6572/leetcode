#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *construct_tree(vector<TreeNode *> &nodes, int left, int right) {
  if (left > right)
    return nullptr;
  int mid = (right + left) / 2;
  TreeNode *cur = nodes[mid];
  cur->left = construct_tree(nodes, left, mid - 1);
  cur->right = construct_tree(nodes, mid + 1, right);
  return cur;
}

TreeNode *balanceBST(TreeNode *root) {
  if (root == nullptr)
    return nullptr;
  stack<TreeNode *> s;
  vector<TreeNode *> vec;
  while (!s.empty() || root) {
    if (root) {
      s.push(root);
      root = root->left;
    } else {
      root = s.top();
      s.pop();
      vec.push_back(root);
      root = root->right;
    }
  }
  return construct_tree(vec, 0, vec.size() - 1);
}
