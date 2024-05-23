#include <utility>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <queue>
using namespace std;
int widthOfBinaryTree(TreeNode *root) {
  if (root == nullptr)
    return 0;
  queue<TreeNode *> q;
  int rs = 1;
  q.push(root);
  while (!q.empty()) {
    int s = q.size();
    int cur = 0;
    bool flag = false;
    for (int i = 0; i < s; ++i) {
      TreeNode *temp = q.front();
      q.pop();
      if (temp == nullptr) {
        q.push(nullptr);
        q.push(nullptr);
        if (cur != 0)
          cur++;
      } else {
        flag = true;
        q.push(temp->left);
        q.push(temp->right);
        cur++;
        if (cur > rs)
          rs = cur;
      }
    }
    if (!flag)
      break;
  }
  return rs;
}

int widthOfBinaryTree2(TreeNode *root) {
  if (root == nullptr)
    return 0;
  queue<pair<TreeNode *, int>> q;
  int rs = 1;
  q.push(pair(root, 1));
  while (!q.empty()) {
    int s = q.size();
    int start = -1;
    int end = -1;
    for (int i = 0; i < s; ++i) {
      auto p = q.front();
      TreeNode *temp = p.first;
      int id = p.second;
      if (start == -1) {
        start = id;
      }
      end = id;
      q.pop();
      if (temp->left)
        q.push(pair(temp->left, (id - start + 1) * 2));
      if (temp->right)
        q.push(pair(temp->right, (id - start + 1) * 2 + 1));
    }
    if (end - start + 1 > rs)
      rs = end - start + 1;
  }
  return rs;
}
