#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;

int findPoisonedDuration(vector<int> &timeSeries, int duration) {
  int i = 0;
  int rs = 0;
  while (i + 1 < timeSeries.size()) {
    rs = min(timeSeries[i + 1] - timeSeries[i], duration);
  }
  rs += duration;
  return rs;
}
