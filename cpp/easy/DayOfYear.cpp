#include <string>
using namespace std;

bool is_runyear(int year) {
  if ((year % 4 == 0 && year % 100) || year % 400 == 0) {
    return true;
  } else {
    return false;
  }
}
int day_of_mounth(int mounth) {
  switch (mounth) {
  case 2:
    return 28;
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
  default:
    return 30;
  }
}
int dayOfYear(string date) {
  int year = 0;
  int mounth = 0;
  int day = 0;
  int index = 0;
  while (date[index] != '-') {
    year = year * 10 + date[index] - '0';
    index++;
  }
  index++;
  while (date[index] != '-') {
    mounth = mounth * 10 + date[index] - '0';
    index++;
  }
  index++;
  while (index < date.size() && date[index] != '-') {
    day = day * 10 + date[index] - '0';
    index++;
  }
  for (int i = 1; i < mounth; ++i) {
    day += day_of_mounth(i);
  }
  return is_runyear(year) && mounth > 2 ? day + 1 : day;
}
