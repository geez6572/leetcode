#include <string>
using namespace std;

string reverseMessage(string message) {
  int left = message.size() - 1;
  int right = left;
  string rs;
  while (left >= 0) {
    while (right >= 0 && message[right] == ' ') {
      right--;
    }
    if (right >= 0) {
      left = right;
    } else {
      break;
    }

    while (left > 0 && message[left] != ' ') {
      left--;
    }

    for (int i = left; i <= right; ++i) {
      rs.push_back(message[i]);
    }
    rs.push_back(' ');
    left = left - 1;
    right = left;
  }
  return rs;
}
