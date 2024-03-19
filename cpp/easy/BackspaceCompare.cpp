#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool backspaceCompare(string s, string t) {
  string s1;
  string t1;
  for (auto c : s) {
    if (s1.size() && c == '#') {
      s1.pop_back();
    } else {
      s1.push_back(c);
    }
  }

  for (auto c : t) {
    if (t1.size() && c == '#') {
      t1.pop_back();
    } else {
      t1.push_back(c);
    }
  }
  cout << s1 << endl;
  cout << t1 << endl;
  return s1 == t1;
}

int main() {
  string s = "y#fo##f";
  string t = "y#f#o##f";
  cout << backspaceCompare(s, t);
  return 0;
}
