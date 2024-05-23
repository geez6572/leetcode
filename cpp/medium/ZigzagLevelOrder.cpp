#include <deque>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void pushin(deque<TreeNode *> &d, TreeNode *node, bool flag) {
  if (flag) {
    d.push_back(node);
  } else {
    d.push_front(node);
  }
}
TreeNode *getout(deque<TreeNode *> &d, bool flag) {
  TreeNode *rs;
  if (flag) {
    rs = d.front();
    d.pop_front();
  } else {
    rs = d.back();
    d.pop_back();
  }
  return rs;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  if (root == nullptr)
    return {};
  deque<TreeNode *> d;
  d.push_back(root);
  vector<vector<int>> rs;
  bool flag = true;
  while (!d.empty()) {
    int len = d.size();
    vector<int> vec(d.size());
    for (int i = 0; i < len; ++i) {
      TreeNode *temp = getout(d, flag);
      vec[i] = temp->val;
      TreeNode *l = temp->left;
      TreeNode *r = temp->right;
      if (!flag) {
        TreeNode *temp = l;
        l = r;
        r = temp;
      }
      if (l)
        pushin(d, l, flag);
      if (r)
        pushin(d, r, flag);
    }
    rs.push_back(vec);
    flag = !flag;
  }
  return rs;
}

int main() {
  TreeNode *root = new TreeNode(3);
  TreeNode *left = new TreeNode(9);
  TreeNode *right = new TreeNode(20);
  root->left = left;
  root->right = right;
  right->left = new TreeNode(15);
  right->right = new TreeNode(7);
  zigzagLevelOrder(root);
  return 0;
}
