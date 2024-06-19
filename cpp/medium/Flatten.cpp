#include <stack>
#include <vector>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using namespace std;
TreeNode *head = nullptr;
TreeNode *last = nullptr;
void flatten(TreeNode *root) {
  stack<TreeNode *> stack;
  vector<TreeNode *> vec;
  while (!stack.empty() || root) {
    if (root) {
      stack.push(root);
      vec.push_back(root);
      root = root->left;
    } else {
      root = stack.top();
      stack.pop();
      root = root->right;
    }
  }
  TreeNode *last = nullptr;
  for (auto i : vec) {
    if (last == nullptr) {
      last = i;
    } else {
      last->right = i;
      last = i;
    }
    last->left = nullptr;
  }
}

int main() {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(2);
  TreeNode *right = new TreeNode(5);
  root->left = left;
  root->right = right;
  left->left = new TreeNode(3);
  left->right = new TreeNode(4);
  right->right = new TreeNode(6);
  flatten(root);
  return 0;
}
