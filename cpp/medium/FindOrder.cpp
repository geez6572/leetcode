#include <queue>
#include <vector>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
  vector<int> in(numCourses, 0);
  vector<vector<int>> out(numCourses);
  // init
  for (int i = 0; i < prerequisites.size(); ++i) {
    in[prerequisites[i][0]]++;
    out[prerequisites[i][1]].push_back(prerequisites[i][0]);
  }

  queue<int> q;
  for (int i = 0; i < numCourses; ++i) {
    if (in[i] == 0)
      q.push(i);
  }
  int count = q.size();
  vector<int> rs;
  while (!q.empty()) {
    int temp = q.front();
    q.pop();
    rs.push_back(temp);
    for (auto i : out[temp]) {
      in[i]--;
      if (in[i] == 0)
        q.push(i);
    }
  }
  if (rs.size() == numCourses)
    return rs;
  return {};
}
