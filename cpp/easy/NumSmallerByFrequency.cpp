#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int frequent(string &str) {
  char cur_c = 'z';
  int cnt = 0;
  for (auto c : str) {
    if (c < cur_c) {
      cur_c = c;
      cnt = 1;
    } else if (c == cur_c)
      cnt++;
  }
  return cnt;
}

vector<int> numSmallerByFrequency(vector<string> &queries,
                                  vector<string> &words) {
  vector<int> wq(words.size(), 0);
  for (int i = 0; i < words.size(); ++i) {
    wq[i] = frequent(words[i]);
  }
  vector<int> rs;
  sort(wq.begin(), wq.end());
  for (auto str : queries) {
    int str_freq = frequent(str);
    int i = 0;
    while (i < wq.size() && wq[i] < str_freq) {
      i++;
    }
    rs.push_back(wq.size() - i);
  }
  return rs;
}

vector<int> numSmallerByFrequency2(vector<string> &queries,
                                   vector<string> &words) {
  vector<int> wq(12, 0);
  for (auto word : words) {
    wq[frequent(word)]++;
  }
  for (int i = 9; i >= 1; --i) {
    wq[i] += wq[i + 1];
  }
  vector<int> rs;
  for (auto word : queries) {
    rs.push_back(wq[frequent(word) + 1]);
  }
  return rs;
}
