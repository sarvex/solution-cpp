#include <vector>

class Solution {
public:
  auto cherryPickup(const std::vector<std::vector<int>>& grid) {
    const auto m = grid.size(), n = grid[0].size();
    std::vector f(n, std::vector(n, -1));
    std::vector g(n, std::vector(n, -1));
    f[0][n - 1] = grid[0][0] + grid[0][n - 1];
    for (int i = 1; i < m; ++i) {
      for (int j1 = 0; j1 < n; ++j1) {
        for (int j2 = 0; j2 < n; ++j2) {
          const int x = grid[i][j1] + (j1 == j2 ? 0 : grid[i][j2]);
          for (int y1 = j1 - 1; y1 <= j1 + 1; ++y1) {
            for (int y2 = j2 - 1; y2 <= j2 + 1; ++y2) {
              if (y1 >= 0 and y1 < n and y2 >= 0 and y2 < n and f[y1][y2] != -1) {
                g[j1][j2] = std::max(g[j1][j2], f[y1][y2] + x);
              }
            }
          }
        }
      }
      swap(f, g);
    }
    int result = 0;
    for (int j1 = 0; j1 < n; ++j1)
      for (int j2 = 0; j2 < n; ++j2) result = std::max(result, f[j1][j2]);

    return result;
  }
};
