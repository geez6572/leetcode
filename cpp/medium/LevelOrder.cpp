// Definition for a Node.
#include <queue>
#include <vector>
using namespace std;
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    if (root == nullptr)
      return {};
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> rs;
    while (!q.empty()) {
      int size = q.size();
      vector<int> curLevel;
      for (int i = 0; i < size; ++i) {
        root = q.front();
        q.pop();
        curLevel.push_back(root->val);
        for (auto &ch : root->children) {
          if (ch)
            q.push(ch);
        }
      }
      rs.push_back(curLevel);
    }
    return rs;
  }
};
