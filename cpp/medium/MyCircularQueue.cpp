#include <iostream>
#include <ostream>
#include <vector>
class MyCircularQueue {
public:
  MyCircularQueue(int k) : queue(k + 1), start(0), end(0), capacity(k + 1) {}

  bool enQueue(int value) {
    if (isFull())
      return false;
    queue[end] = value;
    end = (end + 1) % capacity;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;
    start = (start + 1) % capacity;
    return true;
  }

  int Front() {
    if (isEmpty())
      return -1;
    return queue[start];
  }

  int Rear() {
    if (isEmpty())
      return -1;
    return queue[(end - 1 + capacity) % capacity];
  }

  bool isEmpty() { return start == end; }

  bool isFull() { return ((end + 1) % capacity) == start; }

private:
  std::vector<int> queue;
  int start;
  int end;
  int capacity;
};

int main() {
  MyCircularQueue queue(3);
  std::cout << queue.queue.size() << std::endl;
  std::cout << queue.enQueue(1) << std::endl;
  std::cout << queue.enQueue(2) << std::endl;
  std::cout << queue.enQueue(3) << std::endl;
  return 0;
}
