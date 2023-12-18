#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using std::min;
using std::pair;
using std::queue;
using std::vector;

class Solution {
public:
  auto updateMatrixFast(vector<vector<int>> &mat) {
    const auto m = mat.size();
    const auto n = mat[0].size();
    const auto size = m + n;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0)
          continue;
        int top = size, left = size;
        if (i - 1 >= 0)
          top = mat[i - 1][j];
        if (j - 1 >= 0)
          left = mat[i][j - 1];
        mat[i][j] = min(top, left) + 1;
      }
    }

    for (int i = m - 1; i > -1; i--) {
      for (int j = n - 1; j > -1; j--) {
        if (mat[i][j] == 0)
          continue;
        int bottom = size, right = size;
        if (i + 1 < m)
          bottom = mat[i + 1][j];
        if (j + 1 < n)
          right = mat[i][j + 1];
        mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
      }
    }
    return mat;
  }
};
