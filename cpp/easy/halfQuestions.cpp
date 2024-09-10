#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
int halfQuestions(vector<int> &questions) {
  unordered_map<int, int> map;
  for (auto &i : questions) {
    map[i]++;
  }
  vector<int> count;
  for (auto [_, v] : map) {
    count.push_back(v);
  }
  sort(count.begin(), count.end());
  int rs = 0;
  int n = questions.size() / 2;
  for (auto i = count.rbegin(); i != count.rend(); ++i) {
    if (n > 0) {
      n = n - *i;
      rs++;
    } else {
      break;
    }
  }
  return rs;
}
