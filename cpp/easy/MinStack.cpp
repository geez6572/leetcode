#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
class MinStack {
private:
  vector<int> stack;
  vector<int> min_stack;

public:
  MinStack() { min_stack.push_back(INT_MAX); }

  void push(int val) {
    stack.push_back(val);
    min_stack.push_back(min(min_stack[min_stack.size() - 1], val));
  }

  void pop() {
    stack.pop_back();
    min_stack.pop_back();
  }

  int top() { return stack[stack.size() - 1]; }

  int getMin() { return min_stack[min_stack.size() - 1]; }
};
