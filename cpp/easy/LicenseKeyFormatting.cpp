#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string licenseKeyFormatting(string s, int k) {
  int count = 0;
  string rs;
  for (int i = s.size() - 1; i >= 0; --i) {
    char c = s[i];
    if (c != '-') {
      if (count == 0 && rs.size()) {
        rs.push_back('-');
      }
      if (c <= 'z' && c >= 'a') {
        c = c - 'a' + 'A';
      }
      rs.push_back(c);
      count++;
      if (count == k)
        count = 0;
    }
  }
  reverse(rs.begin(), rs.end());
  return rs;
}
