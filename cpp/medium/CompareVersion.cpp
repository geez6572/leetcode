#include <string>
using namespace std;
int getNum(string &version, int &index) {
  int rs = 0;
  while (index < version.size() && version[index] >= '0' &&
         version[index] <= '9') {
    rs = (rs * 10) + version[index] - '0';
    index++;
  }
  return rs;
}

int compareVersion(string version1, string version2) {
  int index1 = 0;
  int index2 = 0;
  while (index1 < version1.size() || index2 < version2.size()) {
    int num1 = 0;
    int num2 = 0;
    if (index1 < version1.size()) {
      num1 = getNum(version1, index1);
      index1++;
    }
    if (index2 < version2.size()) {
      num2 = getNum(version2, index2);
      index2++;
    }
    if (num1 < num2) {
      return -1;
    } else if (num1 > num2) {
      return 1;
    }
  }
  return 0;
}
