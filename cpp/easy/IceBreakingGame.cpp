#include <vector>

using namespace std;

int iceBreakingGame(int num, int target) {
  vector<bool> table(num, true);
  int cur_index = 0;
  while (num > 1) {
    int rank = target;
    while (rank > 0) {
      if (table[cur_index])
        --rank;
      if (rank == 0) {
        table[cur_index] = false;
        --num;
      }
      cur_index = (cur_index + 1) % table.size();
    }
  }
  for (int i = 0; i <= table.size(); ++i) {
    if (table[i])
      return i;
  }
  return -1;
}
