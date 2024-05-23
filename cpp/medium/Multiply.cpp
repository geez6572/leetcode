#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {
  if (num1[0] == '0' || num2[0] == '0')
    return "0";
  string rs;
  int n1 = num1.size() - 1;
  int n2 = num2.size() - 1;
  for (int i = 0; i < num1.size(); ++i) {
    int front = 0;
    for (int k = 0; k < num2.size(); ++k) {
      int val = (num1[n1 - i] - '0') * (num2[n2 - k] - '0') + front;
      if (val >= 10) {
        front = val / 10;
        val = val % 10;
      } else {
        front = 0;
      }
      if (rs.size() <= i + k) {
        rs.push_back(val + '0');
      } else {
        int temp = (rs[i + k] - '0') + val;
        rs[i + k] = temp % 10 + '0';
        front += temp / 10;
      }
    }
    if (front) {
      rs.push_back(front + '0');
    }
  }
  return rs;
}
