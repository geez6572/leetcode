#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
vector<string> goodsOrder(string goods) {
  vector<string> rs;
  function<void(int)> recur = [&](int index) {
    if (index == goods.size() - 1) {
      rs.push_back(goods);
      return;
    }
    unordered_set<char> set;
    for (int i = index; i < goods.size(); ++i) {
      if (set.count(goods[i]))
        continue;
      set.insert(goods[i]);
      swap(goods[i], goods[index]);
      recur(index + 1);
      swap(goods[i], goods[index]);
    }
  };
  recur(0);
  return rs;
}

int main() {
  vector<string> rs = goodsOrder("agew");
  for (auto s : rs) {
    cout << s << endl;
  }
  return 0;
}
