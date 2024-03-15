#include <algorithm>
#include <string>

using namespace std;

string thousandSeparator(int n) {
  int flag = 0;
  string rs;
  while (n) {
    if (flag == 3) {
      rs.push_back('.');
    } else {
      char c = '0' + (n % 10);
      n = n / 10;
      rs.push_back(c);
    }
    flag = (flag + 1) % 4;
  }
  int s = 0;
  int e = rs.size() - 1;
  while (s < e) {
    char temp = rs[s];
    rs[s] = rs[e];
    rs[e] = temp;
  }
  return rs;
}
