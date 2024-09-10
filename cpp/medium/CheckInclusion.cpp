#include <string>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2) {
  if (s2.size() < s1.size())
    return false;
  vector<int> vec1(26, 0);
  vector<int> vec2(26, 0);
  for (int i = 0; i < s1.size(); ++i) {
    vec1[s1[i] - 'a']++;
    vec2[s2[i] - 'a']++;
  }
  int rs = 0;
  if (vec1 == vec2)
    return true;
  for (int i = s1.size(), start = 0; i < s2.size(); ++i, start++) {
    vec2[s2[start] - 'a']--;
    vec2[s2[i] - 'a']++;
    if (vec1 == vec2)
      return true;
  }
  return false;
}
