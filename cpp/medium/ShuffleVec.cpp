#include <ctime>
#include <iostream>
#include <random>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  Solution(vector<int> &nums) : init(nums), op(nums) {}

  vector<int> reset() {
    op = init;
    return init;
  }

  vector<int> shuffle() {
    // 创建随机数引擎
    std::random_device rd; // 用于获得种子
    std::mt19937 gen(rd()); // 以随机设备作为种子初始化Mersenne Twister引擎

    int cur_index = op.size() - 1;
    while (cur_index > 0) {
      std::uniform_int_distribution<> dis(0, cur_index);
      int r = dis(gen);
      swap(op[cur_index], op[r]);
      cur_index--;
    }

    return op;
  }

private:
  vector<int> init;
  vector<int> op;
};

int main() {
  // 创建随机数引擎
  std::random_device rd; // 用于获得种子
  std::mt19937 gen(rd()); // 以随机设备作为种子初始化Mersenne Twister引擎

  // 定义范围在1到100之间的均匀分布
  std::uniform_int_distribution<> dis(1, 100);

  // 生成并打印10个随机整数
  for (int n = 0; n < 10; ++n) {
    std::cout << dis(gen) << ' ';
  }
  std::cout << std::endl;

  return 0;
}
