#include <stack>
#include <string>
#include <vector>

using namespace std;

// 暴力解法
vector<int> finalPrices(vector<int> &prices) {
  for (int i = 0; i < prices.size(); ++i) {
    for (int k = i + 1; k < prices.size(); ++k) {
      if (prices[i] >= prices[k]) {
        prices[i] -= prices[k];
        break;
      }
    }
  }
  return prices;
}

vector<int> finalPrices2(vector<int> &prices) {
  stack<int> stack;
  for (int i = prices.size() - 1; i >= 0; --i) {
    while (!stack.empty() && stack.top() > prices[i])
      stack.pop();
    int discount = stack.empty() ? 0 : stack.top();
    prices[i] -= discount;
    stack.push(prices[i]);
  }
  return prices;
}

int main() {
  string s;
  return 0;
}
