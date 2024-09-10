#include <algorithm>
#include <vector>
using namespace std;

#define start 0
#define end 1

vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList,
                                         vector<vector<int>> &secondList) {
  int cur_f = 0;
  int cur_s = 0;
  vector<vector<int>> rs;
  while (cur_f < firstList.size() && cur_s < secondList.size()) {
    int s = max(firstList[cur_f][start], secondList[cur_s][start]);
    int e = min(firstList[cur_f][end], secondList[cur_s][end]);
    if (s <= e) {
      vector<int> temp = {s, e};
      rs.push_back(temp);
    }

    if (firstList[cur_f][end] > secondList[cur_s][end])
      cur_s++;
    else if (firstList[cur_f][end] < secondList[cur_s][end])
      cur_f++;
    else {
      cur_f++;
      cur_s++;
    }
  }
  return rs;
}
