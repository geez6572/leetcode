#include <string>

using namespace std;
bool isPalindrome(string s, int left, int right, bool chance) {
  if (left == right) {
    return true;
  }
  while (left < right) {
    if (s[left] != s[right]) {
      if (chance) {
        return isPalindrome(s, left, right - 1, false) ||
               isPalindrome(s, left + 1, right, false);
      }
      return false;
    }
    right--;
    left++;
  }
  return true;
}
bool validPalindrome(string s) {
  return isPalindrome(s, 0, s.size() - 1, true);
}
