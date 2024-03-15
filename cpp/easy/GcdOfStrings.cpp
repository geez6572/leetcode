#include <algorithm>
#include <string>
using namespace std;

string gcdOfStrings(string str1, string str2) {
  int size1 = str1.size();
  int size2 = str2.size();
  int max_size = min(size1, size2);
  while (max_size > 1) {
    if (size1 % max_size == 0 && size2 % max_size == 0)
      break;
    max_size--;
  }
  string pattern1(str1.begin(), str1.begin() + max_size);
  string pattern2(str2.begin(), str2.begin() + max_size);
  if (pattern1 != pattern2)
    return "";
  while (pattern1.size() < size1) {
    pattern1 += pattern1;
  }
  if (pattern1 != str1)
    return "";
  while (pattern2.size() < size2) {
    pattern2 += pattern2;
  }
  if (pattern2 != str2)
    return "";
  return string(str1.begin(), str1.begin() + max_size);
}
