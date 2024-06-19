#include <iostream>
#include <vector>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
  vector<int> in_count(numCourses, 0);
  vector<int> next;
  vector<vector<int>> out_course(numCourses);
  for (auto vec : prerequisites) {
    in_count[vec[0]]++;
    out_course[vec[1]].push_back(vec[0]);
  }
  for (int i = 0; i < in_count.size(); ++i) {
    if (in_count[i] == 0) {
      next.push_back(i);
    }
  }
  int cur = 0;
  while (cur < next.size()) {
    for (auto out : out_course[next[cur]]) {
      in_count[out]--;
      if (in_count[out] == 0)
        next.push_back(out);
    }
    cur++;
  }
  return cur == numCourses;
}

int main() {
  vector<vector<int>> course = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};
  cout << canFinish(5, course);
  return 0;
}
