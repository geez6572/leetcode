#include <vector>

using namespace std;

int findRepeatDocument(vector<int> &documents) {
  int *set = new int[documents.size()]{0};
  for (auto file : documents) {
    if (set[file])
      return file;
    set[file] = 1;
  }
  return -1;
}
