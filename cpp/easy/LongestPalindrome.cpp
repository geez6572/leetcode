#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int longestPalindrome(string s) {
  unordered_set<char> map;
  for (auto c : s) {
    if (map.count(c)) {
      map.erase(c);
    } else {
      map.insert(c);
    }
  }
  return s.size() - (map.empty() ? 0 : map.size() - 1);
}
