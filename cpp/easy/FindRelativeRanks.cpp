#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;

vector<string> findRelativeRanks(vector<int> &score) {
  vector<pair<int, int>> rank;
  for (int i = 0; i < score.size(); ++i) {
    rank.emplace_back(score[i], i);
  }
  sort(rank.begin(), rank.end(),
       [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
  vector<string> rs(score.size());
  for (int i = 0; i < rank.size(); ++i) {
    if (i == 0) {
      rs[rank[i].second] = "Gold Medal";
    } else if (i == 1) {
      rs[rank[i].second] = "Silver Medal";
    } else if (i == 2) {
      rs[rank[i].second] = "Bronze Medal";
    } else {
      rs[rank[i].second] = to_string(i + 1);
    }
  }
  return rs;
}
