#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> nums = {1, 2, 4, 8, 16, 32};
vector<vector<int>> h = vector<vector<int>>(4);
vector<vector<int>> m = vector<vector<int>>(6);
void divideH(int index, int cur, int count) {
  if (count > 3 || index > 3)
    return;
  for (int i = index; i < 4; ++i) {
    if (cur + nums[i] < 12) {
      h[count].push_back(cur + nums[i]);
      divideH(i + 1, cur + nums[i], count + 1);
    }
  }
}

void divideM(int index, int cur, int count) {
  if (count > 5 || index > 5)
    return;
  for (int i = index; i < 6; ++i) {
    if (cur + nums[i] <= 59) {
      m[count].push_back(cur + nums[i]);
      divideM(i + 1, cur + nums[i], count + 1);
    }
  }
}

void comb(vector<string> &rs, int hi, int mi) {
  for (int i = 0; i < h[hi].size(); ++i) {
    string cur = to_string(h[hi][i]) + ":";
    for (int k = 0; k < m[mi].size(); ++k) {
      if (m[mi][k] < 10)
        cur += "0";
      cur += to_string(m[mi][k]);
      rs.push_back(cur);
      cur = to_string(h[hi][i]) + ":";
    }
  }
}
vector<string> readBinaryWatch(int turnedOn) {
  divideH(0, 0, 1);
  divideM(0, 0, 1);
  h[0] = {0};
  m[0] = {0};
  vector<string> rs;
  for (int i = 0; i < h.size(); ++i) {
    for (int k = 0; k < m.size(); ++k) {
      if (i + k == turnedOn) {
        comb(rs, i, k);
      }
    }
  }
  return rs;
}
int main() {
  vector<string> rs = readBinaryWatch(2);
  for (auto s : rs) {
    cout << s << endl;
  }
  return 0;
}
