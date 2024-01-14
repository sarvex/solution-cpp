#include <limits>
#include <vector>

class Solution {
public:
  auto calculateMinimumHP(const std::vector<std::vector<int>>& dungeon) {
    const int m = static_cast<int>(dungeon.size()), n = static_cast<int>(dungeon[0].size());
    std::vector result(m + 1, std::vector(n + 1, std::numeric_limits<int>::max() >> 2));
    result[m][n - 1] = result[m - 1][n] = 1;
    for (int i = m - 1; ~i; --i)
      for (int j = n - 1; ~j; --j) {
        result[i][j] = std::max(1, std::min(result[i + 1][j], result[i][j + 1]) - dungeon[i][j]);
      }
    return result[0][0];
  }
};
