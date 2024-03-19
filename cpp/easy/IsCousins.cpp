#include <queue>
#include <vector>
using namespace std;

// 二叉树数据结构
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isCousins(TreeNode *root, int x, int y) {
  queue<TreeNode *> queue;
  TreeNode *last = root;
  TreeNode *pre_last = root;
  queue.push(root);
  bool flag_x = false;
  bool flag_y = false;
  while (!queue.empty()) {
    TreeNode *temp = queue.front();
    queue.pop();
    if (temp->left && temp->right &&
        ((temp->left->val == x && temp->right->val == y) ||
         temp->left->val == y && temp->right->val == x)) {
      return false;
    }
    if (temp->val == x)
      flag_x = true;
    if (temp->val == y)
      flag_y = true;
    if (temp->left) {
      queue.push(temp->left);
      last = temp->left;
    }

    if (temp->right) {
      queue.push(temp->right);
      last = temp->right;
    }
    if (temp == pre_last) {
      if (flag_x && flag_y) {
        return true;
      }
      if (flag_y || flag_x) {
        return false;
      }
      pre_last = last;
    }
  }
  return false;
}

void dfs(TreeNode *root, int p, int d, vector<int> &depth,
         vector<int> &parent) {
  if (root == nullptr)
    return;
  depth[root->val] = d;
  parent[root->val] = p;
  dfs(root->left, root->val, d + 1, depth, parent);
  dfs(root->right, root->val, d + 1, depth, parent);
}

// 递归解法
bool isCousins2(TreeNode *root, int x, int y) {
  vector<int> depth(101, -1);
  vector<int> parent(101, -1);
  dfs(root, -1, 0, depth, parent);
  return depth[x] == depth[y] && parent[x] != parent[y];
}
