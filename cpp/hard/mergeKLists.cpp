#include "../dataStruct/ListNode.h"
#include <queue>
#include <vector>
using namespace std;

struct mycmp {
  bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
  priority_queue<ListNode *, vector<ListNode *>, mycmp> queue;
  ListNode *dummy = new ListNode();
  ListNode *cur = dummy;
  for (int i = 0; i < lists.size(); i++) {
    if (lists[i]) {
      queue.push(lists[i]);
    }
  }
  while (!queue.empty()) {
    cur->next = queue.top();
    cur = cur->next;
    queue.pop();
    if (cur->next) {
      queue.push(cur->next);
    }
    cur->next = nullptr;
  }
  return dummy->next;
}
