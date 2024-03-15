#include <string>
#include <vector>

using namespace std;

string removeDuplicates(string s) {
  vector<char> stack;
  for (auto c : s) {
    if (stack.empty() || c != stack[stack.size() - 1]) {
      stack.push_back(c);
      continue;
    }
    stack.pop_back();
  }
  return string(stack.data());
}
