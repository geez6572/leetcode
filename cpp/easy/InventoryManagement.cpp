#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &nums, int index, int size) {
  int temp = nums[index];
  for (int i = index * 2 + 1; i < size; i = i * 2 + 1) {
    if (i + 1 < size && nums[i] > nums[i + 1])
      ++i;
    if (nums[i] < temp) {
      nums[index] = nums[i];
      index = i;
    } else {
      break;
    }
  }
  nums[index] = temp;
}

vector<int> inventoryManagement(vector<int> &stock, int cnt) {
  for (int i = stock.size() / 2 - 1; i >= 0; --i) {
    heapify(stock, i, stock.size());
  }
  vector<int> rs(cnt, 0);
  for (int i = 0; i < cnt; ++i) {
    heapify(stock, 0, stock.size() - i);
    rs[i] = stock[0];
    stock[0] = stock[stock.size() - i - 1];
  }
  return rs;
}

int main() {
  vector<int> nums = {0, 2, 3, 6, 4, 9, 7, 1};
  inventoryManagement(nums, 2);
  return 0;
}
