#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<double> calcEquation(vector<vector<string>> &equations,
                            vector<double> &values,
                            vector<vector<string>> &queries) {
  unordered_map<string, vector<int>> map;
  for (int i = 0; i < equations.size(); i++) {
    map[equations[i][0]].push_back(i);
    map[equations[i][1]].push_back(i);
  }

  vector<bool> visited(equations.size(), false);
  vector<double> res;
  function<bool(string, string &, double &)> dfs = [&](string cur, string &dis,
                                                       double &rs) -> bool {
    if (cur == dis) {
      res.push_back(rs);
      return true;
    }
    for (auto i : map[cur]) {
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      double back = rs;
      if (cur == equations[i][0]) {
        rs = rs * values[i];
        if (dfs(equations[i][1], dis, rs)) {
          visited[i] = false;
          return true;
        }
      } else {
        rs = rs * (1.0 / values[i]);
        if (dfs(equations[i][0], dis, rs)) {
          visited[i] = false;
          return true;
        }
      }
      visited[i] = false;
      rs = back;
    }
    return false;
  };

  for (int i = 0; i < queries.size(); i++) {
    if (!map.count(queries[i][0]) || !map.count(queries[i][1])) {
      res.push_back(-1.0);
      continue;
    }
    if (queries[i][0] == queries[i][1] && map.count(queries[i][0])) {
      res.push_back(1.0);
      continue;
    }
    double curRs = 1.0;
    bool finded = dfs(queries[i][0], queries[i][1], curRs);
    if (!finded) {
      res.push_back(-1.0);
    }
  }
  return res;
}

int main() {
  vector<vector<string>> equations = {{"x1", "x2"}};
  vector<double> values = {3.0};
  vector<vector<string>> queries = {{"x9", "x2"}, {"x9", "x9"}};
  auto rs = calcEquation(equations, values, queries);
  for (auto i : rs) {
    cout << i << " ";
  }
  return 0;
}
