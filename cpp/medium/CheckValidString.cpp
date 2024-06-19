#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkValidString(string s) {
  vector<int> stack;
  vector<int> star;
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (c == '(') {
      stack.push_back(i);
    } else if (c == ')') {
      if (!stack.empty()) {
        stack.pop_back();
      } else if (!star.empty()) {
        star.pop_back();
      } else {
        return false;
      }
    } else {
      star.push_back(i);
    }
  }
  int star_index = 0;
  int stack_index = 0;
  while (star_index < star.size() && stack_index < stack.size()) {
    if (star[star_index] > stack[stack_index]) {
      stack_index++;
    }
    star_index++;
  }
  return stack_index == stack.size();
}

int main() {
  string s = "(((((*(((((*((**((**(((***)*)))))))(())(()))())((*()()(((()((()*("
             "())*(()**)()(())";
  cout << checkValidString(s);
  return 0;
}
