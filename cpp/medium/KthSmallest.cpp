#include <stack>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;

int kthSmallest(TreeNode *root, int k) {
  stack<TreeNode *> q;
  int cur = 0;
  while (!q.empty() || root) {
    if (root) {
      q.push(root);
      root = root->left;
    } else {
      root = q.top();
      q.pop();
      cur++;
      if (cur == k)
        return root->val;
      root = root->right;
    }
  }
  return 0;
}
