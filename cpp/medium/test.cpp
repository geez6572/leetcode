#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> l;
  l.push_back(8);
  l.push_front(9);
  l.push_front(10);
  list<int>::iterator iter;
  for (auto it = l.begin(); it != l.end(); ++it) {
    if (*it == 9) {
      iter = it;
    }
  }
  l.erase(iter);
  l.push_back(*iter);
  for (auto i = l.begin(); i != l.end(); ++i) {
    bool rs = (i == iter);
    cout << rs << endl;
  }
  return 0;
}
