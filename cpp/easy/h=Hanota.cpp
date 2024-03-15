#include <vector>

using namespace std;

void recursion(vector<int> &A, vector<int> &B, vector<int> &C, int n) {
  if (n == 1) {
    C.push_back(A.back());
    A.pop_back();
    return;
  }
  recursion(A, C, B, n - 1);
  C.push_back(A.back());
  A.pop_back();
  recursion(B, A, C, n - 1);
}

void hanota(vector<int> &A, vector<int> &B, vector<int> &C) {
  recursion(A, B, C, A.size());
}
