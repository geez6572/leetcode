#include <string>

using namespace std;

bool isSubsequence(string s, string t) {
  int s_index = 0;
  for (int i = 0; i < t.size() && s_index < s.size(); ++i) {
    if (s[s_index] == t[i]) {
      s_index++;
    }
  }
  return s_index == s.size();
}
