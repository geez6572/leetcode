#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int rs = 0;

bool canpush(vector<vector<bool>> &board, int x, int y) {
  for (int i = 0; i < x; ++i) {
    if (board[i][y])
      return false;
  }
  int de_x = 1;
  int de_y = 1;
  while (x - de_x >= 0 && y - de_y >= 0) {
    if (board[x - de_x][y - de_y])
      return false;
    de_x++;
    de_y++;
  }
  de_x = 1;
  de_y = 1;
  while (x - de_x >= 0 && y + de_y < board.size()) {
    if (board[x - de_x][y + de_y])
      return false;
    de_x++;
    de_y++;
  }
  return true;
}

void recursion(vector<vector<bool>> &board, int line) {
  for (int i = 0; i < board.size(); ++i) {
    if (canpush(board, line, i)) {
      if (line == board.size() - 1) {
        rs++;
        return;
      }
      board[line][i] = true;
      recursion(board, line + 1);
      board[line][i] = false;
    }
  }
}
int totalNQueens1(int n) {
  rs = 0;
  vector<vector<bool>> board(n, vector(n, false));
  recursion(board, 0);
  return rs;
}

// 优化

int backtrace(int n, int line, unordered_set<int> &col,
              unordered_set<int> &angle1, unordered_set<int> &angle2) {
  if (line == n) {
    return 1;
  } else {
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (col.count(i))
        continue;
      int cur_angle1 = line + i;
      if (angle1.count(cur_angle1))
        continue;
      int cur_angle2 = line - i;
      if (angle2.count(cur_angle2))
        continue;
      col.insert(i);
      angle1.insert(cur_angle1);
      angle2.insert(cur_angle2);
      count += backtrace(n, line + 1, col, angle1, angle2);
      col.erase(i);
      angle1.erase(cur_angle1);
      angle2.erase(cur_angle2);
    }
    return count;
  }
}
int totalNQueens2(int n) {
  unordered_set<int> col;
  unordered_set<int> angle1;
  unordered_set<int> angle2;
  return backtrace(n, 0, col, angle1, angle2);
}

int main() {
  for (int i = 0; i < 5; ++i) {
    for (int k = 0; k < 5; ++k) {
      cout << i + k << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (int i = 0; i < 5; ++i) {
    for (int k = 0; k < 5; ++k) {
      cout << i - k << " ";
    }
    cout << endl;
  }
  return 0;
}
