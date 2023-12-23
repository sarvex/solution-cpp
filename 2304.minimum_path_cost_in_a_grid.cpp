#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
  auto minPathCost(const std::vector<std::vector<int>>& grid, const std::vector<std::vector<int>>& moveCost) {
    const auto m = grid.size(), n = grid[0].size();
    std::vector<int> f = grid[0];
    for (int i = 1; i < m; ++i) {
      std::vector g(n, std::numeric_limits<int>::max());
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) { g[j] = std::min(g[j], f[k] + moveCost[grid[i - 1][k]][j] + grid[i][j]); }
      }
      f = std::move(g);
    }
    return *std::min_element(f.begin(), f.end());
  }
};
