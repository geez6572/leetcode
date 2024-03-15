#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool findTarget(TreeNode *root, int k) {
  unordered_set<int> set;
  stack<TreeNode *> stack;
  while (root || !stack.empty()) {
    if (root) {
      if (set.count(root->val)) {
        return true;
      }
      set.insert(k - root->val);
      stack.push(root);
      root = root->left;
    } else {
      root = stack.top();
      stack.pop();
      root = root->right;
    }
  }
  return false;
}
