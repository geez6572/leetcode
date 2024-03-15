struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool find_node(TreeNode *root, TreeNode *target) {
  if (root == target) {
    return true;
  }
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == p || root == q || root == nullptr) {
    return root;
  }
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);

  if (left && right) {
    return root;
  }
  return left ? left : right;
}
