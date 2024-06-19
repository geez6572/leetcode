#include <stack>
#include <vector>
using namespace std;

int compress(vector<char> &chars) {
  int i = 0;
  int append = 0;
  while (i < chars.size()) {
    int start = i;
    while (i < chars.size() - 1 && chars[i] == chars[i + 1])
      i++;
    int num = i - start + 1;
    chars[append++] = chars[start];
    if (num > 1) {
      stack<int> s;
      while (num) {
        s.push(num % 10);
        num = num / 10;
      }
      while (!s.empty()) {
        chars[append++] = '0' + s.top();
        s.pop();
      }
    }
    i++;
  }
  return append;
}

int main() {
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  compress(chars);
  return 0;
}
