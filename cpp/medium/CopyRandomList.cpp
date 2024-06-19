#include <unordered_map>
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

Node *findNode(Node *head, Node *newhead, Node *find) {
  while (head != find) {
    head = head->next;
    newhead = newhead->next;
  }
  return newhead;
}
Node *copyRandomList(Node *head) {
  Node *node = head;
  Node *newhead = new Node(0);
  Node *dummy = newhead;
  while (node) {
    Node *cp = new Node(node->val);
    dummy->next = cp;
    dummy = dummy->next;
    node = node->next;
  }
  node = head;
  dummy = newhead->next;
  while (node) {
    dummy->random = findNode(head, newhead->next, node->random);
  }
  return newhead->next;
}

Node *copyRandomList2(Node *head) {
  Node *node = head;
  Node *newhead = new Node(0);
  Node *dummy = newhead;
  std::unordered_map<Node *, Node *> map;
  while (node) {
    Node *cp = new Node(node->val);
    map[node] = cp;
    dummy->next = cp;
    dummy = dummy->next;
    node = node->next;
  }
  node = head;
  dummy = newhead->next;
  while (node) {
    if (node->random) {
      dummy->random = map[node->random];
    }
    node = node->next;
    dummy = dummy->next;
  }
  return newhead->next;
}

Node *copyRandomList3(Node *head) {
  Node *travel = head;
  while (travel) {
    Node *temp = new Node(travel->val);
    temp->next = travel->next;
    travel->next = temp;
    travel = temp->next;
  }

  travel = head;
  while (travel) {
    Node *newTravel = travel->next;
    if (travel->random)
      newTravel->random = travel->random->next;
    travel->next = newTravel->next;
  }
  travel = head;
  Node *rs = new Node(0);
  Node *last = rs;
  while (travel) {
    Node *newTravel = travel->next;
    travel->next = newTravel->next;
    newTravel->next = last->next;
    last->next = newTravel;
    last = newTravel;
    travel = travel->next;
  }
  return rs->next;
}
