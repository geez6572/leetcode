#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int bsearch(vector<int> &nums, int start, int end, int target) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (nums[mid] > target) {
      end = mid - 1;
    } else if (nums[mid] == target) {
      return mid;
    } else {
      start = mid + 1;
    }
  }
  return -1;
}
bool consTree(vector<int> &postorder, int s1, int e1, vector<int> &inorder,
              int s2, int e2) {
  if (s1 > e1)
    return true;
  int iroot = bsearch(inorder, s2, e2, postorder[e1]);
  if (iroot == -1) {
    int bb = 0;
    return false;
  }
  int leftnodes = iroot - s2;
  bool l = consTree(postorder, s1, s1 + leftnodes - 1, inorder, s2, iroot - 1);
  bool r = consTree(postorder, s1 + leftnodes, e1 - 1, inorder, iroot + 1, e2);
  return l && r;
}

bool verifyTreeOrder(vector<int> &postorder) {
  vector<int> inorder = postorder;
  sort(inorder.begin(), inorder.end());
  return consTree(postorder, 0, postorder.size() - 1, inorder, 0,
                  inorder.size() - 1);
}

bool verifyTreeOrder2(vector<int> &postorder) {
  stack<int> stk;
  int root = INT_MAX;
  for (int i = postorder.size() - 1; i >= 0; --i) {
    if (postorder[i] > root)
      return false;
    while (!stk.empty() && stk.top() > postorder[i]) {
      root = stk.top();
      stk.pop();
    }
  }
}
int main() {
  vector<int> nums = {4, 6, 5, 9, 8};
  cout << verifyTreeOrder(nums);
  return 0;
}
