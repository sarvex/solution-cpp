#include <vector>

class Solution {
public:
  auto numberOfPaths(std::vector<std::vector<int>>& grid, const int k) {
    const auto n = grid.size(), m = grid[0].size();
    std::vector result(n, std::vector(m, std::vector(k, 0LL)));
    result[0][0][grid[0][0] % k] = 1;
    for (int i = 1; i < n; i++) for (int j = 0; j < k; j++) result[i][0][(j + grid[i][0]) % k] = result[i - 1][0][j];
    for (int i = 1; i < m; i++) for (int j = 0; j < k; j++) result[0][i][(j + grid[0][i]) % k] = result[0][i - 1][j];

    for (int i = 1; i < n; i++)
      for (int j = 1; j < m; j++)
        for (int l = 0; l < k; l++)
          result[i][j][(l + grid[i][j]) % k] = (result[i - 1][j][l] + result[i][j - 1][l]) % 1000000007;

    return static_cast<int>(result[n - 1][m - 1][0]);
  }
};
