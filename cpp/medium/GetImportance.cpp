#include <vector>
using namespace std;
class Employee {
public:
  int id;
  int importance;
  vector<int> subordinates;
};

int getImportance(vector<Employee *> employees, int id) {
  Employee *point = nullptr;
  for (auto e : employees) {
    if (e->id == id) {
      point = e;
      break;
    }
  }
  if (point == nullptr)
    return 0;
  int rs = point->importance;
  vector<int> sub = point->subordinates;
  int sub_index = 0;
  while (sub_index < sub.size()) {
    for (auto e : employees) {
      if (e->id == sub[sub_index]) {
        if (!e->subordinates.empty())
          sub.insert(sub.end(), e->subordinates.begin(), e->subordinates.end());
        rs += e->importance;
        break;
      }
    }
    sub_index++;
  }
  return rs;
}
