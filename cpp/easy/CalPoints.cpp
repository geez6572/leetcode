#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calPoints(vector<string> &operations) {
  vector<int> stk;
  int rs = 0;
  for (auto c : operations) {
    if (c[0] == '+') {
      int cur = stk[stk.size() - 1] + stk[stk.size() - 2];
      rs += cur;
      stk.push_back(cur);
    } else if (c[0] == 'C') {
      rs -= stk[stk.size() - 1];
      stk.pop_back();
    } else if (c[0] == 'D') {
      int cur = stk[stk.size() - 1] * 2;
      stk.push_back(cur);
      rs += cur;
    } else {
      rs += stoi(c);
      stk.push_back(stoi(c));
    }
  }
  return rs;
}

int main() {
  vector<string> operations = {"5", "2", "C", "D", "+"};
  cout << calPoints(operations);
  return 0;
}
