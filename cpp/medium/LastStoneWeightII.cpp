#include <algorithm>
#include <vector>

using namespace std;

int lastStoneWeightII(vector<int> &stones) {
  if (stones.size() <= 1)
    return stones[0];
  int sum = 0;
  for (int stone : stones) {
    sum += stone;
  }
  int target = sum / 2;
  vector<int> dp(target + 1, 0);
  for (int i = 0; i < stones.size(); i++) {
    for (int k = target; k >= stones[i]; k--) {
      dp[k] = max(dp[k], dp[k - stones[i]] + stones[i]);
    }
  }
  return sum - (dp[target] * 2);
}
