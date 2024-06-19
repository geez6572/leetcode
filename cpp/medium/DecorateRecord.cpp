#include "../dataStruct/BinaryTree.h"
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> decorateRecord(TreeNode *root) {
  if (root == nullptr)
    return {};
  queue<TreeNode *> q;
  q.push(root);
  bool flag = true;
  stack<int> s;
  vector<vector<int>> rs;
  while (!q.empty()) {
    int curSize = q.size();
    vector<int> vec;
    for (int i = 0; i < curSize; ++i) {
      TreeNode *temp = q.front();
      q.pop();
      q.push(temp->left);
      q.push(temp->right);
      vec.push_back(temp->val);
    }
    if (!flag) {
      reverse(vec.begin(), vec.end());
    }
    rs.push_back(vec);
    flag = !flag;
  }
  return rs;
}
