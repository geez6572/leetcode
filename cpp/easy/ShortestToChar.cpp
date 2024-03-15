#include <algorithm>
#include <climits>
#include <deque>
#include <string>
#include <vector>
using namespace std;

vector<int> shortestToChar(string s, char c) {
  vector<int> answer(s.size());
  int left = -1;
  int right = 0;
  deque<int> q;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == c) {
      q.push_back(i);
    }
  }
  right = q.front();
  q.pop_front();
  for (int i = 0; i < answer.size(); ++i) {
    if (left < 0) {
      answer[i] = right - i;
    } else {
      answer[i] = min(i - left, right - i);
    }
    if (right == i) {
      left = right;
      if (q.empty()) {
        right = INT_MAX;
      } else {
        right = q.front();
        q.pop_front();
      }
    }
  }
  return answer;
}

vector<int> shortestToChar2(string s, char c) {
  int n = s.size();
  vector<int> answer(n);
  for (int i = 0, pre = -n; i < n; ++i) {
    if (s[i] == c) {
      pre = i;
    }
    answer[i] = i - pre;
  }

  for (int i = n - 1, pre = INT_MAX; i >= 0; --i) {
    if (s[i] == c) {
      pre = i;
    }
    answer[i] = min(answer[i], pre - i);
  }
  return answer;
}
