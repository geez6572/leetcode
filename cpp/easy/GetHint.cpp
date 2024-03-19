#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string getHint(string secret, string guess) {
  int bulls = 0;
  int cows = 0;
  vector<int> s_map(10, 0);
  vector<int> g_map(10, 0);
  for (int i = 0; i < secret.size(); ++i) {
    if (secret[i] == guess[i]) {
      bulls++;
    } else {
      if (s_map[guess[i] - '0']) {
        cows++;
        s_map[guess[i] - '0']--;
      } else {
        g_map[guess[i] - '0']++;
      }

      if (g_map[secret[i] - '0']) {
        cows++;
        g_map[secret[i] - '0']--;
      } else {
        s_map[secret[i] - '0']++;
      }
    }
  }
  string rs;
  if (bulls) {
    rs += to_string(bulls);
    rs.push_back('A');
  }
  if (cows) {
    rs += to_string(cows);
    rs.push_back('B');
  }
  return rs;
}
