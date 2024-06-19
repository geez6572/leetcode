#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int maximumSwap(int num) {
  vector<int> to_v;
  vector<pair<int, int>> stack;
  int temp = num;
  while (temp) {
    int cur = temp % 10;
    to_v.push_back(cur);
    if (stack.empty() || cur >= stack.back().first)
      stack.push_back(make_pair(cur, to_v.size() - 1));
    temp /= 10;
  }
  for (int i = to_v.size() - 1; i >= 0; --i) {
    if (to_v[i] < stack.back().first) {
      auto cur = stack.back();
      stack.pop_back();
      while (!stack.empty() && stack.back().first == cur.first) {
        cur = stack.back();
        stack.pop_back();
      }
      swap(to_v[i], to_v[cur.second]);
      break;
    }
    stack.pop_back();
  }
  for (auto i = to_v.rbegin(); i != to_v.rend(); ++i) {
    temp = temp * 10 + (*i);
  }
  return temp;
}

int maximumSwap2(int num) {
  string s = to_string(num);
  int maxIndex = s.size() - 1;
  int index1 = -1;
  int index2 = -1;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] > s[maxIndex]) {
      maxIndex = i;
    } else if (s[i] < s[maxIndex]) {
      index1 = i;
      index2 = maxIndex;
    }
  }
  if (index1 != -1)
    swap(s[index1], s[index2]);
  return stoi(s);
}

int main() {
  cout << maximumSwap(2736);
  cout << maximumSwap(9973);
  return 0;
}
