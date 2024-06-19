#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNumber(vector<int> &nums) {
  int c = 0;
  for (auto i : nums) {
    c = c ^ i;
  }

  vector<int> rs;
  int d = 3 ^ 5;
  for (auto i : nums) {
    if ((c & i) == i) {
      rs.push_back(i);
    }
  }
  return rs;
}

int main() {
  int a = 2324;
  int b = 9822;
  int c = a ^ b;
  cout << (a & c) << endl;
  cout << (b & c) << endl;
  return 0;
}
