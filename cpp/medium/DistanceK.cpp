#include "../dataStruct/BinaryTree.h"
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<TreeNode *, TreeNode *> map;
vector<int> rs;

void findParent(TreeNode *node) {
  if (node->left != nullptr) {
    map[node->left] = node;
    findParent(node->left);
  }
  if (node->right != nullptr) {
    map[node->right] = node;
    findParent(node->right);
  }
}
void bfs(TreeNode *cur, TreeNode *from, int k) {
  if (cur == nullptr)
    return;
  if (k == 0) {
    rs.push_back(cur->val);
    return;
  }
  if (map[cur] != from) {
    bfs(map[cur], cur, k - 1);
  }
  if (cur->left != from) {
    bfs(cur->left, cur, k - 1);
  }
  if (cur->right != from) {
    bfs(cur->right, from, k - 1);
  }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
  findParent(root);
  bfs(target, nullptr, k);
  return rs;
}
