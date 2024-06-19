#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split_ip(const string &queryIP) {
  vector<string> rs;
  string s;
  for (auto c : queryIP) {
    if (c != '.' && c != ':') {
      s.push_back(c);
    } else {
      rs.push_back(s);
      s.clear();
    }
  }
  rs.push_back(s);
  return rs;
}
string validIPAddress(string queryIP) {
  vector<string> sp = split_ip(queryIP);
  if (sp.size() == 4) {
    for (auto s : sp) {
      if (s.size() > 3 || s.empty())
        return "Neither";
      int num = 0;
      for (auto c : s) {
        if (c == '0' && s.size() > 1) {
          return "Neither";
        }
        num = num * 10 + c - '0';
      }
      if (num > 255)
        return "Neither";
    }
    return "IPv4";
  } else if (sp.size() == 8) {
    for (auto s : sp) {
      if (s.size() > 4 || s.empty())
        return "Neither";
      for (auto c : s) {
        if (!isdigit(c) && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F'))
          return "Neither";
      }
    }
    return "IPv6";
  } else {
    return "Neither";
  }
}

int main() {
  string s = "2001:0db8:85a3:0:0:8A2E:0370:7334";
  cout << validIPAddress(s);
  return 0;
}
