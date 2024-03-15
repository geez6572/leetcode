#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isIsomorphic1(string s, string t) {
  vector<int> mapping1(128, -1);
  vector<int> mapping2(128, -1);
  for (int i = 0; i < s.size(); ++i) {
    int si = s[i];
    int ti = t[i];
    if (mapping1[si] == -1) {
      mapping1[si] = ti;
    } else if (mapping1[si] != ti) {
      return false;
    }
    if (mapping2[ti] == -1) {
      mapping2[ti] = si;
    } else if (mapping2[ti] != si) {
      return false;
    }
  }
  return true;
}

bool isIsomorphic2(string s, string t) {
  unordered_map<char, char> s2t;
  unordered_map<char, char> t2s;
  int len = s.size();
  for (int i = 0; i < len; ++i) {
    char si = s[i];
    char ti = t[i];
    if ((s2t.count(si) && s2t[si] != ti) || (t2s.count(ti) && t2s[ti] != si))
      return false;
    s2t[si] = ti;
    t2s[ti] = si;
  }

  return true;
}

int main() {}
