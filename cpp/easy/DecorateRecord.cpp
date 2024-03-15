#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> decorateRecord(TreeNode *root) {
  vector<vector<int>> rs;
  if (root == nullptr) {
    return rs;
  }
  queue<TreeNode *> q;
  q.push(root);
  TreeNode *last = root;
  vector<int> elements;
  TreeNode *next_last;
  while (!q.empty()) {
    TreeNode *temp = q.front();
    q.pop();
    elements.push_back(temp->val);
    if (temp->left) {
      q.push(temp->left);
      next_last = temp->left;
    }
    if (temp->right) {
      q.push(temp->right);
      next_last = temp->right;
    }
    if (temp == last) {
      rs.push_back(elements);
      elements.resize(0);
      last = next_last;
    }
  }
  return rs;
}
