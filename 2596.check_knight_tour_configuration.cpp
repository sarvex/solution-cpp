#include <cmath>
#include <functional>
#include <vector>

class Solution {
public:
  bool checkValidGrid(std::vector<std::vector<int>>& grid) {
    if (grid[0][0] != 0) { return false; }
    const int n = grid.size();
    std::vector<std::pair<int, int>> pos(n * n);
    for (int i = 0; i < n; ++i) { for (int j = 0; j < n; ++j) { pos[grid[i][j]] = { i, j }; } }
    for (int i = 1; i < n * n; ++i) {
      const auto [x1, y1] = pos[i - 1];
      const auto [x2, y2] = pos[i];
      const auto dx = std::abs(x1 - x2);
      const auto dy = std::abs(y1 - y2);
      if ((dx != 1 or dy != 2) and (dx != 2 or dy != 1)) return false;
    }
    return true;
  }
};
