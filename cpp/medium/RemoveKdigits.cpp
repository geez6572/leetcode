#include <iostream>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
  if (num.size() <= k)
    return "0";
  string rs;
  int index = 0;
  while (index < num.size()) {
    while (!rs.empty() && rs.back() > num[index] && k) {
      rs.pop_back();
      k--;
    }
    rs.push_back(num[index]);
    index++;
  }
  while (k > 0) {
    rs.pop_back();
    k--;
  }
  index = 0;
  while (index < rs.size() && rs[index] == '0')
    index++;
  rs = string(rs.begin() + index, rs.end());
  return rs.empty() ? "0" : rs;
}

int main() {
  cout << removeKdigits("10200", 1);
  return 0;
}
