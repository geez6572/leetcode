
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void recursion(TreeNode *node, int cur, int &rs) {
  if (node == nullptr)
    return;
  cur = cur * 10 + node->val;
  if (node->left == nullptr && node->right == nullptr) {
    rs += cur;
  }
  if (node->left) {
    recursion(node->left, cur, rs);
  }
  if (node->right) {
    recursion(node->right, cur, rs);
  }
}

int sumNumbers(TreeNode *root) {
  int rs = 0;
  recursion(root, 0, rs);
  return rs;
}
