#include <string>
#include <vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
  if (s.size() < p.size())
    return {};
  vector<int> rs;
  vector<int> sc(26, 0);
  vector<int> pc(26, 0);
  for (int i = 0; i < p.size(); ++i) {
    sc[s[i] - 'a']--;
    pc[p[i] - 'a']++;
  }
  int left = 0;
  int right = p.size() - 1;
  while (right < s.size()) {
    if (sc == pc)
      rs.push_back(left);
    if (right == s.size() - 1)
      break;
    sc[s[left++] - 'a']--;
    sc[s[++right] - 'a']++;
  }
  return rs;
}

vector<int> findAnagrams2(string s, string p) {
  if (s.size() < p.size())
    return {};
  vector<int> rs;
  vector<int> count(26, 0);
  for (int i = 0; i < p.size(); ++i) {
    count[p[i] - 'a']++;
    count[s[i] - 'a']--;
  }
  int differ = 0;
  for (auto &i : count) {
    if (i != 0)
      differ++;
  }
  int left = 0;
  int right = p.size();
  if (differ == 0)
    rs.push_back(left);
  while (right < s.size()) {
    count[s[left] - 'a']--;
    if (count[s[left] - 'a'] == 0)
      differ--;
    else if (count[s[left] - 'a'] == -1)
      differ++;

    count[s[right] - 'a']++;
    if (count[s[right] - 'a'] == 1)
      differ++;
    else if (count[s[right] - 'a'] == 0)
      differ--;
    if (differ == 0)
      rs.push_back(left + 1);
    right++;
    left++;
  }
  return rs;
}

int main() {
  findAnagrams2("baa", "aa");
  return 0;
}
