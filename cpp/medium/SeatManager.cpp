#include <queue>
#include <utility>

class SeatManager {
public:
  SeatManager(int n) {
    for (int i = 1; i <= n; i++) {
      heap.push(i);
    }
  }

  int reserve() {
    int rs = heap.top();
    heap.pop();
    return rs;
  }

  void unreserve(int seatNumber) { heap.push(seatNumber); }

private:
  std::priority_queue<int> heap;
};
