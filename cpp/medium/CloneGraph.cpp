// Definition for a Node.
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
private:
  unordered_map<int, Node *> map;

public:
  Node *cloneGraph(Node *node) {
    if (node == nullptr)
      return nullptr;
    Node *cur = new Node(node->val);
    map[cur->val] = cur;
    for (auto &i : node->neighbors) {
      if (!map.count(i->val)) {
        cur->neighbors.push_back(cloneGraph(i));
      } else {
        cur->neighbors.push_back(map[i->val]);
      }
    }
    return cur;
  }
};
