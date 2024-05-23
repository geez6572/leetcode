#include <climits>
#include <string>
using namespace std;

int myAtoi(string s) {
  int cur = 0;
  while (s[cur] == ' ')
    cur++;
  bool flag = true;
  if (s[cur] == '-') {
    flag = false;
    cur++;
  } else if (s[cur] == '+') {
    cur++;
  }
  long rs = 0;
  while (cur < s.size() && s[cur] >= '0' && s[cur] <= '9') {
    rs = (rs * 10) + s[cur] - '0';
    if (flag && rs >= INT_MAX)
      return INT_MAX;
    else if (rs > INT_MAX)
      return INT_MIN;
    cur++;
  }
  return flag ? rs : -rs;
}
