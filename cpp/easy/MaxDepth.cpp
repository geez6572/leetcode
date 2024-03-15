#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int maxDepth(string s) {
  stack<char> stack;
  int rs = 0;
  for (auto c : s) {
    if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      rs = max(rs, (int)stack.size());
      stack.pop();
    }
  }
  return rs;
}
