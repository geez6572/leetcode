#include <queue>
#include <vector>

using namespace std;

int lastStoneWeight(vector<int> &stones) {
  priority_queue<int> heap;
  for (int stone : stones) {
    heap.push(stone);
  }

  while (heap.size() > 1) {
    int a = heap.top();
    heap.pop();
    int b = heap.top();
    heap.pop();
    if (a - b > 0) {
      heap.push(a - b);
    }
  }
  return heap.size() == 1 ? heap.top() : 0;
}
