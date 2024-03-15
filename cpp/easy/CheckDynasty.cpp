#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool checkDynasty(vector<int> &places) {
  sort(places.begin(), places.end());
  int count = 0;
  while (places[count] == 0) {
    count++;
  }
  for (int i = count; i < places.size() - 1; ++i) {
    if (places[i] == places[i + 1])
      return false;
    count = count - (places[i + 1] - places[i] - 1);
  }
  return count >= 0;
}

int main() {
  vector<int> places = {0, 6, 9, 0, 7};
  cout << checkDynasty(places);
  return 0;
}
