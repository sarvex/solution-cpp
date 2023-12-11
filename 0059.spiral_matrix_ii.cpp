#include <vector>

using std::vector;

class Solution {
public:
  const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  auto generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int i = 0, j = 0, k = 0;
    for (int v = 1; v <= n * n; ++v) {
      ans[i][j] = v;
      int x = i + dirs[k][0], y = j + dirs[k][1];
      if (x < 0 or y < 0 or x >= n or y >= n or ans[x][y]) {
        k = (k + 1) % 4;
        x = i + dirs[k][0], y = j + dirs[k][1];
      }
      i = x, j = y;
    }
    return ans;
  }
};
