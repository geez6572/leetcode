#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
  unordered_set<int> set;
  stack<int> stack;
  int push_cur = 0;
  int pop_cur = 0;
  while (push_cur < pushed.size()) {
    if (pushed[push_cur] == popped[pop_cur]) {
      push_cur++;
      pop_cur++;
      continue;
    }
    if (set.count(popped[pop_cur])) {
      if (popped[pop_cur] != stack.top())
        return false;
      set.erase(popped[pop_cur]);
      stack.pop();
      pop_cur++;
    } else {
      stack.push(pushed[push_cur]);
      set.insert(pushed[push_cur]);
      push_cur++;
    }
  }
  while (!stack.empty() && pop_cur < popped.size()) {
    if (stack.top() != popped[pop_cur])
      return false;
    stack.pop();
    pop_cur++;
  }
  if (!stack.empty() || pop_cur < popped.size())
    return false;
  return true;
}

bool validateStackSequences2(vector<int> &pushed, vector<int> &popped) {
  stack<int> s;
  int cur = 0;
  for (int i = 0; i < pushed.size(); ++i) {
    s.push(pushed[i]);
    while (!s.empty() && s.top() == popped[cur]) {
      s.pop();
      cur++;
    }
  }
  return s.empty();
}
