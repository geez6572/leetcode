#include <cctype>
#include <stack>
#include <string>
using namespace std;
bool isop(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }
bool priority(char a, char b) {
  if (a == '*' || a == '/')
    return true;
  if (b == '*' || b == '/')
    return false;
  return true;
}

int calculate(string s) {
  stack<int> nums;
  stack<char> ops;
  int i = 0;
  while (i < s.size()) {
    char c = s[i];
    if (isdigit(c)) {
      int n = 0;
      while (i < s.size() && isdigit(s[i])) {
        n = (n * 10) + s[i] - '0';
        i++;
      }
      nums.push(n);
    } else if (isop(c)) {
      while (!ops.empty() && priority(ops.top(), c)) {
        char temp = ops.top();
        ops.pop();
        int a = nums.top();
        nums.pop();
        int b = nums.top();
        nums.pop();
        switch (temp) {
        case '+':
          nums.push(b + a);
          break;
        case '-':
          nums.push(b - a);
          break;
        case '*':
          nums.push(b * a);
          break;
        case '/':
          nums.push(b / a);
          break;
        }
      }
      ops.push(c);
      i++;
    } else {
      i++;
    }
    int bk = 0;
  }
  while (!ops.empty()) {
    char temp = ops.top();
    ops.pop();
    int a = nums.top();
    nums.pop();
    int b = nums.top();
    nums.pop();
    switch (temp) {
    case '+':
      nums.push(b + a);
      break;
    case '-':
      nums.push(b - a);
      break;
    case '*':
      nums.push(b * a);
      break;
    case '/':
      nums.push(b / a);
      break;
    }
  }
  return nums.top();
}

int main() {
  string s = "1*2-3/4+5*6-7*8+9/10";
  calculate(s);
  return 0;
}
