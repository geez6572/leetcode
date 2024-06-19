#include "../dataStruct/ListNode.h"

ListNode *oddEvenList(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return head;
  ListNode *oddLast = head;
  ListNode *evenLast = head->next;
  ListNode *travel = evenLast->next;
  while (travel) {
    evenLast->next = travel->next;
    evenLast = evenLast->next;
    travel->next = oddLast->next;
    oddLast->next = travel;
    oddLast = travel;
    if (evenLast)
      travel = evenLast->next;
    else
      travel = nullptr;
  }
  return head;
}

int main() { return 0; }
