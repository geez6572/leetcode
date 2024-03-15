class MyHashMap {
public:
  MyHashMap() { map = new Map[10001]; }

  void put(int key, int value) {}

  int get(int key) {}

  void remove(int key) {}

private:
  struct Map {
    int key;
    int value;
  };
  Map *map;
};
