#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> nextp = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool pattern(vector<vector<char>> &board, const string &word, int x, int y,
             int cur) {
  if (cur == word.size())
    return true;
  if (board[x][y] != word[cur])
    return false;
  board[x][y] = '0';
  for (int i = 0; i < 4; ++i) {
    int next_x = x + nextp[i][0];
    int next_y = y + nextp[i][1];
    if (next_x >= 0 && next_x < board.size() && y >= 0 && y < board[0].size()) {
      bool rs = pattern(board, word, next_x, next_y, cur + 1);
      if (rs)
        return true;
    }
  }
  board[x][y] = word[cur];
  return false;
}

bool exist(vector<vector<char>> &board, string word) {
  for (int i = 0; i < board.size(); ++i) {
    for (int k = 0; k < board[0].size(); ++k) {
      bool rs = pattern(board, word, i, k, 0);
      if (rs)
        return true;
    }
  }
  return false;
}

int main() {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  cout << exist(board, "SEE");
  return 0;
}
