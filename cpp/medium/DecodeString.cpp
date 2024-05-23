#include <algorithm>
#include <cctype>
#include <stack>
#include <string>
#include <vector>
using namespace std;

/**
 * 递归解法
 */
string parse(string &s, int start, int end) {
  string rs;
  int i = start;
  while (i <= end) {
    if (s[i] >= '0' && s[i] <= '9') {
      int num = 0;
      while (s[i] >= '0' && s[i] <= '9') {
        num = (num) * 10 + s[i] - '0';
        i++;
      }
      int start = i;
      int count = 0;
      while (count != 0 || start == i) {
        if (s[i] == '[')
          count++;
        else if (s[i] == ']')
          count--;
        i++;
      }
      string temp = parse(s, start + 1, i - 2);
      for (int k = 0; k < num; ++k)
        rs += temp;
    } else {
      rs.push_back(s[i++]);
    }
  }
  return rs;
}
string decodeString(string s) { return parse(s, 0, s.size() - 1); }

/**
 * 栈解法
 */

string decodeString2(string s) {
  vector<string> sk;
  string rs;
  int index = 0;
  while (index < s.size()) {
    if (isdigit(s[index])) {
      string digit;
      while (isdigit(s[index])) {
        digit.push_back(s[index++]);
      }
      sk.push_back(digit);
    } else if (s[index] == ']') {
      string sub;
      while (sk.back() != "[") {
        sub += sk.back();
        sk.pop_back();
      }
      reverse(sub.begin(), sub.end());
      sk.pop_back();

      int num = stoi(sk.back());
      sk.pop_back();
      for (int i = 0; i < num; ++i)
        sk.push_back(sub);
      index++;
    } else {
      sk.push_back(string(1, s[index++]));
    }
  }
  for (auto i : sk) {
    rs += i;
  }
  reverse(rs.begin(), rs.end());
  return rs;
}

int main() {
  decodeString2("3[a]2[bc]");
  return 0;
}
