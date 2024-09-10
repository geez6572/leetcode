#include "../dataStruct/BinaryTree.h"
#include <iostream>
#include <unordered_map>
#include <vector>

int rs = 0;
std::vector<long> s;
std::unordered_map<long, int> map;
void recursion(TreeNode *root, int targetSum) {
  if (root == nullptr)
    return;
  long last = 0;
  if (!s.empty())
    last = s.back();
  long cur = (long)root->val + (long)last;
  std::cout << std::endl;
  std::cout << "cur last value:" << last << std::endl;
  std::cout << "cur root value:" << root << std::endl;
  std::cout << "cur value:" << cur << std::endl;
  std::cout << std::endl;
  s.push_back(cur);
  if (map.count(s.back() - targetSum))
    rs += map[s.back() - targetSum];
  if (cur == (long)targetSum)
    rs++;
  if (map.count(cur))
    map[cur]++;
  else
    map[cur] = 1;
  recursion(root->left, targetSum);
  recursion(root->right, targetSum);
  s.pop_back();
  map[cur]--;
}

int pathSum(TreeNode *root, int targetSum) {
  recursion(root, targetSum);
  return rs;
}

int main() {
  TreeNode *root = new TreeNode(1000000000);
  root->left = new TreeNode(1000000000);
  root->left->left = new TreeNode(294967296);
  root->left->left->left = new TreeNode(1000000000);
  root->left->left->left->left = new TreeNode(1000000000);
  root->left->left->left->left->left = new TreeNode(1000000000);
  std::cout << pathSum(root, 0);

  return 0;
}
