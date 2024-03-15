#include <string>
#include <vector>
using namespace std;

string countAndSay(int n) {
  if (n == 1) {
    return "1";
  }
  string pre = countAndSay(n - 1);
  int count = 1;
  string rs;
  int index = 0;
  while (index < pre.size()) {
    if (index + 1 == pre.size() || pre[index + 1] != pre[index]) {
      rs.push_back(count + '0');
      rs.push_back(pre[index]);
      count = 1;
    } else if (pre[index + 1] == pre[index]) {
      count++;
    }
    index++;
  }
  return rs;
}
