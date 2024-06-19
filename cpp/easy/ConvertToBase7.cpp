#include <algorithm>
#include <string>
using namespace std;

string convertToBase7(int num) {
  string rs;
  while (num) {
    rs.push_back(num % 7);
    num = num / 7;
  }
  reverse(rs.begin(), rs.end());
  return rs;
}
