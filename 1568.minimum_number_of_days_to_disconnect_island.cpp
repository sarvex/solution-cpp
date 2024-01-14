#include <vector>
#include <functional>

class Solution {
public:
  auto minDays(std::vector<std::vector<int>>& grid) {
    const std::vector dirs{ -1, 0, 1, 0, -1 };
    const auto m = grid.size(), n = grid[0].size();

    const std::function<void(int, int)> search = [&](const int i, const int j) {
      grid[i][j] = 2;
      for (int k = 0; k < 4; ++k)
        if (const int x = i + dirs[k], y = j + dirs[k + 1]; x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1)
          search(x, y);
    };

    const std::function<int()> count = [&]() {
      int result = 0;
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == 1) {
            search(i, j);
            ++result;
          }
      for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (grid[i][j] == 2) grid[i][j] = 1;
      return result;
    };

    if (count() != 1) return 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          grid[i][j] = 0;
          if (count() != 1) return 1;
          grid[i][j] = 1;
        }
    return 2;
  }
};
