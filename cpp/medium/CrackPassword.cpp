#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
  string num1 = a + b;
  string num2 = b + a;
  return num1 > num2;
}

string crackPassword(vector<int> &password) {
  vector<string> rs_vec;
  for (auto i : password) {
    rs_vec.push_back(to_string(i));
  }
  sort(rs_vec.begin(), rs_vec.end(), cmp);
  string rs;
  for (auto s : rs_vec) {
    rs += s;
  }
  return rs;
}
