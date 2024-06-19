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

bool isCompleteTree(TreeNode *root) {
  if (root == nullptr)
    return true;
  queue<TreeNode *> queue;
  queue.push(root);
  bool flag = false;
  while (!queue.empty()) {
    TreeNode *temp = queue.front();
    queue.pop();
    if (temp == nullptr) {
      while (!queue.empty()) {
        temp = queue.front();
        queue.pop();
        if (temp != nullptr)
          return false;
      }
    } else {
      queue.push(temp->left);
      queue.push(temp->right);
    }
  }
  return true;
}
