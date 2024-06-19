struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool test(TreeNode *A, TreeNode *B) {
  if (B == nullptr)
    return true;
  if (A == nullptr || A->val != B->val)
    return false;
  bool left = test(A->left, B->left);
  bool right = test(A->right, B->right);
  return left && right;
}
bool isSubStructure(TreeNode *A, TreeNode *B) {
  if (A == nullptr)
    return false;
  if (A->val == B->val) {
    bool rs = test(A, B);
    if (rs)
      return rs;
  }
  bool left = isSubStructure(A->left, B);
  if (left)
    return true;
  bool right = isSubStructure(A->right, B);
  if (right)
    return right;
  return false;
}
