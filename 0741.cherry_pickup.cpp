#include <vector>

class Solution {
public:
  auto cherryPickup(const std::vector<std::vector<int>>& grid) {
    const int n = static_cast<int>(grid.size()), inf = -1e9;
    std::vector result(n << 1, std::vector(n, std::vector(n, inf)));
    result[0][0][0] = grid[0][0];
    for (int k = 1; k < n * 2 - 1; ++k) {
      for (int i1 = 0; i1 < n; ++i1) {
        for (int i2 = 0; i2 < n; ++i2) {
          const int j1 = k - i1, j2 = k - i2;
          if (j1 < 0 or j1 >= n or j2 < 0 or j2 >= n or grid[i1][j1] == -1 or grid[i2][j2] == -1) continue;
          int t = grid[i1][j1];
          if (i1 != i2) t += grid[i2][j2];
          for (int x1 = i1 - 1; x1 <= i1; ++x1)
            for (int x2 = i2 - 1; x2 <= i2; ++x2)
              if (x1 >= 0 and x2 >= 0)
                result[k][i1][i2] = std::max(result[k][i1][i2], result[k - 1][x1][x2] + t);
        }
      }
    }
    return std::max(0, result[n * 2 - 2][n - 1][n - 1]);
  }
};
