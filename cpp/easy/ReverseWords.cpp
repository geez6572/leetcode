#include <string>

using namespace std;

void reverse_index(string &s, int left, int right) {
  if (left >= right)
    return;
  while (left < right) {
    auto temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    left++;
    right--;
  }
}

string reverseWords(string s) {
  int left = 0;
  int right = 0;
  while (left < s.size()) {
    while (left < s.size() && s[left] == ' ') {
      left++;
    }
    right = left;
    while (right < s.size() && s[right] != ' ') {
      right++;
    }
    reverse_index(s, left, right - 1);
    left = right;
  }
  return s;
}
