#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

bool find_target(const string &senate, vector<bool> &disabled, int index) {
  int k = (index + 1) % senate.size();
  while (k != index) {
    if (!disabled[k] && senate[k] != senate[index]) {
      disabled[k] = true;
      return true;
    }
    k = (k + 1) % senate.size();
  }
  return false;
}

string predictPartyVictory(string senate) {
  vector<bool> disabled(senate.size(), false);
  int i = 0;
  while (true) {
    if (disabled[i]) {
      i = (i + 1) % senate.size();
      continue;
    }
    bool finded = find_target(senate, disabled, i);
    if (!finded) {
      if (senate[i] == 'R')
        return "Ridiant";
      else
        return "Dire";
    }
    i = (i + 1) % senate.size();
  }
  return " ";
}

// 优化
string predictPartyVictory2(string senate) {
  bool R = true;
  bool D = true;
  int flag = 0;
  while (R && D) {
    R = false;
    D = false;
    for (int i = 0; i < senate.size(); ++i) {
      if (senate[i] == 'R') {
        if (flag < 0) {
          senate[i] = '0';
        } else {
          R = true;
        }
        flag++;
      }
      if (senate[i] == 'D') {
        if (flag > 0) {
          senate[i] = '0';
        } else {
          D = true;
        }
        flag--;
      }
    }
  }
  return R ? "Radiant" : "Dire";
}

int main() {
  cout << predictPartyVictory("RDD");
  return 0;
}
