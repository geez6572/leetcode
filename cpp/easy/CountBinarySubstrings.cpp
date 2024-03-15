#include <string>
#include <vector>
using namespace std;

int countBinarySubstrings(string s) {
  int index = 0;
  char pre = s[0];
  int pre_count = 0;
  int cur_count = 0;
  int rs = 0;
  while (index < s.size()) {
    if (s[index] == pre) {
      cur_count++;
    } else {
      pre_count = cur_count;
      cur_count = 1;
    }
    if (cur_count <= pre_count) {
      rs++;
    }
    pre = s[index];
  }
  return rs;
}
