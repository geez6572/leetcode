#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

char dismantlingAction(string arr) {
  unordered_map<char, bool> map;
  for (auto a : arr) {
    map[a] = (map.find(a) == map.end());
  }
  for (int i = 0; i < arr.size(); ++i) {
    if (map[arr[i]])
      return arr[i];
  }
  return ' ';
}
