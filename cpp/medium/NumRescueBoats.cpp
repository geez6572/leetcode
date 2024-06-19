#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int numRescueBoats(vector<int> &people, int limit) {
  sort(people.begin(), people.end());
  int l = 0;
  int r = people.size() - 1;
  int rs = 0;
  while (l <= r) {
    if (people[r] + people[l] > limit) {
      r--;
    } else {
      l++;
      r--;
    }
    rs++;
  }
  return rs;
}

int main() {
  vector<int> people = {1, 2};
  cout << numRescueBoats(people, 3);
  return 0;
}
