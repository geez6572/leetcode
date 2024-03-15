#include <vector>
using namespace std;

bool canFill(const vector<vector<int>> &image, int sr, int sc, int target) {
  if (!(sr >= 0 && sr < image.size() && sc >= 0 && sc < image[0].size())) {
    return false;
  }
  return image[sr][sc] == target;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                              int color) {
  if (!(sr >= 0 && sr < image.size() && sc >= 0 && sc < image[0].size())) {
    return image;
  }
  int target = image[sr][sc];
  image[sr][sc] = color;
  if (canFill(image, sr + 1, sc, target)) {
    floodFill(image, sr + 1, sc, color);
  }
  if (canFill(image, sr - 1, sc, target)) {
    floodFill(image, sr - 1, sc, color);
  }
  if (canFill(image, sr, sc + 1, target)) {
    floodFill(image, sr, sc + 1, color);
  }
  if (canFill(image, sr, sc - 1, target)) {
    floodFill(image, sr, sc - 1, color);
  }
  return image;
}
