#include <vector>
using namespace std;

int countBattleships(vector<vector<char>> &board) {
  int rs = 0;
  int row = board.size();
  int col = board[0].size();
  for (int i = 0; i < row; ++i) {
    for (int k = 0; k < col; ++k) {
      if (board[i][k] == 'X') {
        if (i > 0 && board[i - 1][k] == 'X')
          continue;
        if (k > 0 && board[i][k - 1] == 'X')
          continue;
        rs++;
      }
    }
  }
  return rs;
}
