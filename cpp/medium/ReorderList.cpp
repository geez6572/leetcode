
#include <stack>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};

void reorderList(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast->next) {
    fast = fast->next;
    if (!fast->next)
      break;
    fast = fast->next;
    slow = slow->next;
  }
  ListNode *another = slow->next;
  slow->next = nullptr;
  stack<ListNode *> s;
  while (another) {
    s.push(another);
    another = another->next;
  }
  slow = head;
  fast = head->next;
  while (!s.empty()) {
    ListNode *temp = s.top();
    s.pop();
    temp->next = fast;
    slow->next = temp;
    slow = fast;
    fast = fast->next;
  }
}

int main() {
  ListNode *root = new ListNode(1);
  root->next = new ListNode(2);
  root->next->next = new ListNode(3);
  root->next->next->next = new ListNode(4);
  reorderList(root);
  return 0;
}
