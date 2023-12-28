#include <functional>
#include <vector>

class Solution {
public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    const int m = grid.size(), n = grid[0].size();
    int result = 0;
    constexpr std::vector dirs { -1, 0, 1, 0, -1 };
    std::function<void(int, int)> search = [&](const int i, const int j) {
      grid[i][j] = '0';
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k], y = j + dirs[k + 1];
        if (x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == '1') search(x, y);
      }
    };
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          search(i, j);
          ++result;
        }
      }
    }
    return result;
  }
};
