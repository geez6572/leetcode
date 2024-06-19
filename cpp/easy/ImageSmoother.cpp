#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                           {0, 1},   {1, -1}, {1, 0},  {1, 1}};
vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
  vector<vector<int>> rs(img.size(), vector<int>(img[0].size()));
  for (int i = 0; i < img.size(); ++i) {
    for (int k = 0; k < img[0].size(); ++k) {
      int cur = img[i][k];
      int count = 1;
      for (auto &xy : dir) {
        int nexti = i + xy[0];
        int nextk = k + xy[1];
        if (nexti >= 0 && nexti < img.size() && nextk >= 0 &&
            nextk < img[0].size()) {
          count++;
          cur += img[nexti][nextk];
        }
      }
      rs[i][k] = cur / count;
    }
  }
  return rs;
}

int main() {
  vector<vector<int>> img = {
      {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13}, {14, 15, 16}};
  vector<vector<int>> rs = imageSmoother(img);
  for (auto vec : rs) {
    for (auto i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
