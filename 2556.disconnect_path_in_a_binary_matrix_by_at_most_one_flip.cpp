#include <functional>
#include <vector>

class Solution {
public:
  bool isPossibleToCutPath(std::vector<std::vector<int>>& grid) {
    const auto m = grid.size(), n = grid[0].size();
    std::function<bool(int, int)> dfs = [&](const int i, const int j) -> bool {
      if (i >= m or j >= n or grid[i][j] == 0) return false;
      if (i == m - 1 and j == n - 1) return true;
      grid[i][j] = 0;
      return dfs(i + 1, j) or dfs(i, j + 1);
    };
    const bool a = dfs(0, 0);
    grid[0][0] = grid[m - 1][n - 1] = 1;
    const bool b = dfs(0, 0);
    return not (a and b);
  }
};
