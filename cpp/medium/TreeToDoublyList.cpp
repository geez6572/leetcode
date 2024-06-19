#include <vector>
class Node {
public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = nullptr;
    right = nullptr;
  }

  Node(int _val, Node *_left, Node *_right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

using namespace std;
void inOrder(Node *cur, vector<Node *> &nodes) {
  if (cur == nullptr)
    return;
  inOrder(cur->left, nodes);
  nodes.push_back(cur);
  inOrder(cur->right, nodes);
}

Node *treeToDoublyList(Node *root) {
  vector<Node *> nodes;
  inOrder(root, nodes);
  int last = nodes.size();
  for (int i = 0; i < last; ++i) {
    nodes[i]->left = nodes[(i - 1 + last) % last];
    nodes[i]->right = nodes[(i + 1) % last];
  }
  return nodes[0];
}
