#include <string>
using namespace std;
string simplifyPath(string path) {
  string rs;
  rs.push_back('/');
  int index = 1;
  while (index < path.size()) {
    string cur;
    if (path[index] == '.') {
      while (index < path.size() && path[index] != '/') {
        cur.push_back(path[index]);
        index++;
      }
      if (cur.size() > 2 || cur.back() != '.') {
        rs += cur;
      } else if (cur.size() == 2 && rs.size() != 1) {
        bool flag = false;
        while (!(rs.back() == '/' && flag)) {
          if (rs.back() == '/')
            flag = true;
          rs.pop_back();
        }
      }
    } else if (path[index] == '/') {
      if (rs.back() != '/')
        rs.push_back('/');
      index++;
    } else {
      while (index < path.size() && path[index] != '/') {
        cur.push_back(path[index]);
        index++;
      }
      rs += cur;
    }
  }
  if (rs.back() == '/' && rs.size() != 1)
    rs.pop_back();
  return rs;
}
