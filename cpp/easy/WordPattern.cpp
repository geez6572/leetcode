#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool wordPattern(string pattern, string s) {
  unordered_map<char, string> c2s;
  unordered_map<string, char> s2c;
  std::vector<char> c(pattern.begin(), pattern.end());
  std::istringstream iss(s);
  std::vector<std::string> words;
  std::string word;
  while (iss >> word) {
    words.push_back(word);
  }
  if (c.size() != words.size())
    return false;

  int len = c.size();
  for (int i = 0; i < len; ++i) {
    if (c2s.count(c[i]) && c2s[c[i]] != words[i])
      return false;
    c2s[c[i]] = words[i];
    if (s2c.count(words[i]) && s2c[words[i]] != c[i])
      return false;
    s2c[words[i]] = c[i];
  }
  return true;
}

int main() {
  wordPattern("fsadf", "cat dog cat dsf df");
  return 0;
}
