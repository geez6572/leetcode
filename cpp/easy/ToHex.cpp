#include <string>

using namespace std;

string toHex(int num1) {
  string rs = "";
  unsigned int num = static_cast<unsigned int>(num1);
  while (num) {
    int temp = num & 15;
    num = num >> 4;
    char element;
    switch (temp) {
    case 10:
      element = 'a';
      break;
    case 11:
      element = 'b';
      break;
    case 12:
      element = 'c';
      break;
    case 13:
      element = 'd';
      break;
    case 14:
      element = 'e';
      break;
    case 15:
      element = 'f';
      break;
    default:
      element = '0' + temp;
    }
    rs.push_back(element);
  }
  int left = 0;
  int right = rs.size() - 1;
  while (left < right) {
    char c = rs[left];
    rs[left] = rs[right];
    rs[right] = c;
    left++;
    right--;
  }
  return rs;
}

string compressString(string S) {
  int count = 1;
  string rs;
  for (int i = 0; i < S.size(); ++i) {
    if (i == S.size() - 1 || S[i] != S[i + 1]) {
      rs.push_back(S[i]);
      rs = rs + to_string(count);
      count = 1;
    } else {
      count++;
    }
  }
}
