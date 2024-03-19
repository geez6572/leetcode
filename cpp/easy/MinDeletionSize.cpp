#include <string>
#include <vector>

using namespace std;

int minDeletionSize(vector<string> &strs) {
  vector<bool> deleted(strs[0].size(), false);
  int rs = 0;
  for (int i = 1; i < strs.size(); ++i) {
    for (int k = 0; k < strs[0].size(); ++k) {
      if (strs[i][k] <= strs[i - 1][k] && !deleted[k]) {
        rs++;
        deleted[k] = true;
      }
    }
  }
  return rs;
}
