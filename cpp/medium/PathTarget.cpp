#include "../dataStruct/BinaryTree.h"
#include <vector>
using namespace std;

vector<vector<int>> rs;
void dfs(TreeNode *node, vector<int> &sequence, int cur, int target) {
  if (node == nullptr)
    return;
  cur += node->val;
  sequence.push_back(node->val);
  if (node->right == nullptr && node->left == nullptr && cur == target) {
    rs.push_back(sequence);
  }

  dfs(node->left, sequence, cur, target);
  dfs(node->right, sequence, cur, target);
  sequence.pop_back();
}

vector<vector<int>> pathTarget(TreeNode *root, int target) {
  vector<int> sequence;
  dfs(root, sequence, 0, target);
  return rs;
}
