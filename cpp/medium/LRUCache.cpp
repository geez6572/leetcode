#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;
class LRUCache {
public:
  LRUCache(int capacity) : cache_size(capacity), cur(0) {}

  int get(int key) {
    if (map.count(key)) {
      map[key].date = cur++;
      struct value_date temp;
      temp.value = key;
      temp.date = map[key].date;
      q.push(temp);
      return map[key].value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (!map.count(key) && map.size() >= cache_size) {
      int rs = remove_key();
      map.erase(rs);
    }
    map[key].value = value;
    map[key].date = cur++;
    struct value_date temp;
    temp.value = key;
    temp.date = map[key].date;
    q.push(temp);
  }

private:
  int cache_size;
  struct value_date {
    int value;
    int date;
  };
  int cur;
  unordered_map<int, struct value_date> map;
  queue<struct value_date> q;

  int remove_key() {
    while (!q.empty()) {
      struct value_date temp = q.front();
      q.pop();
      if (map.count(temp.value) && map[temp.value].date == temp.date) {
        return temp.value;
      }
    }
    return 0;
  }
};

// 优化版本
class LRUCache2 {
private:
  struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;
    Node() {
      key = -1;
      value = -1;
      prev = nullptr;
      next = nullptr;
    }
  };
  unordered_map<int, Node *> map;
  Node *head;
  Node *tail;
  int cache_size;

public:
  LRUCache2(int capacity) : cache_size(capacity) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->next = head;
  }

  int get(int key) {
    if (map.count(key)) {
      Node *cur_node = map[key];
      cur_node->prev->next = cur_node->next;
      cur_node->next->prev = cur_node->prev;
      cur_node->next = tail;
      cur_node->prev = tail->prev;
      tail->prev->next = cur_node;
      tail->prev = cur_node;
      return cur_node->value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (!map.count(key) && map.size() >= cache_size) {
      Node *remove_node = head->next;
      head->next = remove_node->next;
      remove_node->next->prev = head;
      remove_node->prev = nullptr;
      remove_node->next = nullptr;
      map.erase(remove_node->key);
      delete remove_node;
    }
    if (!map.count(key)) {
      Node *new_node = new Node();
      new_node->key = key;
      new_node->value = value;
      new_node->next = tail;
      new_node->prev = tail->prev;
      tail->prev->next = new_node;
      tail->prev = new_node;
      map[key] = new_node;
    } else {
      map[key]->value = value;
      get(key);
    }
  }
};

class LRUCache3 {
private:
  struct kv {
    int key;
    int value;
  };
  int cache_size;
  unordered_map<int, list<kv>::iterator> map;
  list<kv> link;

public:
  LRUCache3(int capacity) : cache_size(capacity) {}

  int get(int key) {
    if (map.count(key)) {
      auto cur_it = map[key];
      link.splice(link.end(), link, cur_it);
      // link.erase(cur_it);
      // link.push_back(*cur_it);
      return cur_it->value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (!map.count(key) && map.size() >= cache_size) {
      auto start = link.front();
      link.pop_front();
      map.erase(start.key);
    }

    if (!map.count(key)) {
      kv temp;
      temp.key = key;
      temp.value = value;
      link.emplace_back(temp);
      map[key] = std::prev(link.end());
    } else {
      map[key]->value = value;
      get(key);
    }
  }
};

int main() {
  LRUCache3 *l = new LRUCache3(2);
  l->put(1, 1);
  l->put(2, 2);
  cout << l->get(1) << endl;
  l->put(3, 3);
  cout << l->get(2) << endl;
  l->put(4, 4);
  cout << l->get(1) << endl;
  cout << l->get(3) << endl;
  cout << l->get(4) << endl;
  return 0;
}
