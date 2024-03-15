#include <string>
#include <vector>

using namespace std;

string addStrings(string num1, string num2) {
  vector<char> rs;
  int num1_index = num1.size() - 1;
  int num2_index = num2.size() - 1;
  bool more_than_ten = false;
  while (num1_index >= 0 || num2_index >= 0) {
    int temp = 0;
    if (num1_index >= 0)
      temp = num1[num1_index--] - '0';
    if (num2_index >= 0)
      temp = num2[num2_index--] - '0';
    if (more_than_ten)
      temp++;
    if (temp >= 10)
      more_than_ten = true;
    else
      more_than_ten = false;
    temp = temp % 10;
    rs.push_back('0' + temp);
  }
  if (more_than_ten)
    rs.push_back('1');
  string str(rs.rbegin(), rs.rend());
  return str;
}
