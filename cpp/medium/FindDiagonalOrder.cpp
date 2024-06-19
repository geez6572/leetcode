#include <iostream>
#include <vector>
using namespace std;

void getNext(vector<vector<int>> &mat, int &x, int &y, int flag) {
  if (flag) {
    if (y < mat[0].size())
      y++;
    if (x > 0)
      x--;
  } else {
    if (x < mat.size())
      x++;
    else
      y++;
  }
}
vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
  int x = 0;
  int y = 0;
  int flag = true;
  int count = 0;
  vector<int> rs;
  while (count < mat.size() * mat[0].size()) {
    rs.push_back(mat[x][y]);
    if (flag) {
      if (y < mat[0].size() - 1 && x > 0) {
        x--;
        y++;
      } else if (y < mat[0].size() - 1) {

        flag = !flag;
        y++;
      } else {
        flag = !flag;
        x++;
      }
    } else {
      if (x < mat.size() - 1 && y > 0) {
        x++;
        y--;
      } else if (x < mat.size() - 1) {
        flag = !flag;
        x++;
      } else {
        flag = !flag;
        y++;
      }
    }
    count++;
  }
  return rs;
}

int main() {
  vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> rs = findDiagonalOrder(nums);
  for (auto i : rs) {
    cout << i << ",";
  }
  return 0;
}
