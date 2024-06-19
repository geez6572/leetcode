#include <list>
#include <string>
#include <vector>
class FrontMiddleBackQueue {
public:
  FrontMiddleBackQueue() { mid = que.end(); }

  void pushFront(int val) {
    que.push_front(val);
    if (mid == que.end() || que.size() % 2 == 0)
      mid--;
  }

  void pushMiddle(int val) {
    if (que.empty() || que.size() % 2) {
      mid = que.insert(mid, val);
    } else {
      mid = que.insert(++mid, val);
    }
  }

  void pushBack(int val) {
    que.push_back(val);
    if (mid == que.end())
      mid--;
    else if (que.size() % 2)
      mid++;
  }

  int popFront() {
    if (que.empty())
      return -1;

    int val = que.front();
    que.pop_front();

    if (que.empty() || que.size() == 1) {
      mid = que.begin();
    } else if (que.size() % 2)
      mid++;
    return val;
  }

  int popMiddle() {
    if (que.empty())
      return -1;
    int val = *mid;
    mid = que.erase(mid);

    if (que.empty() || que.size() == 1) {
      mid = que.begin();
    } else if (que.size() % 2 == 0)
      mid--;
    return val;
  }

  int popBack() {
    if (que.empty())
      return -1;
    int val = que.back();
    que.pop_back();
    if (que.empty()) {
      mid = que.end();
    } else if (que.size() % 2 == 0)
      mid--;
    return val;
  }

  std::list<int> que;
  std::list<int>::iterator mid;
};

int main() {

  FrontMiddleBackQueue q;
  int cur = 1;
  std::vector<std::string> op = {
      "pushMiddle", "popBack",    "popMiddle",  "popMiddle",  "pushBack",
      "pushFront",  "popFront",   "pushMiddle", "pushMiddle", "popMiddle",
      "popMiddle",  "pushMiddle", "popMiddle",  "pushMiddle"};
  for (auto s : op) {
    if (s == "pushFront") {
      q.pushFront(cur++);
    } else if (s == "popFront") {
      q.popFront();
    } else if (s == "pushBack") {
      q.pushBack(cur++);
    } else if (s == "popBack") {
      q.popBack();
    } else if (s == "pushMiddle") {
      q.pushMiddle(cur++);
    } else {
      q.popMiddle();
    }
  }
  return 0;
}
