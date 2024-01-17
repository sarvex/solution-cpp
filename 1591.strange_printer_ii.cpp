#include <functional>
#include <vector>

class Solution {
public:
  auto isPrintable(const std::vector<std::vector<int>>& grid) {
    const auto m = grid.size(), n = grid[0].size();
    std::vector table(61, std::vector(4, 0));
    std::vector seen(61, -1);

    const std::function<bool(int)> dfs = [&](const int col) {
      seen[col] = 1;
      for (int i = table[col][0]; i <= table[col][2]; i++) {
        for (int j = table[col][3]; j <= table[col][1]; j++) {
          const int x = grid[i][j];
          if (x == col) continue;
          if (seen[x] == 1) return false;
          bool result = true;
          if (seen[x] == 0) result = dfs(x);
          if (result == 0) return false;
        }
      }
      seen[col] = 2;
      return true;
    };

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (const int col = grid[i][j]; seen[col] == -1) {
          seen[col] = 0;
          table[col][0] = i;
          table[col][1] = j;
          table[col][2] = i;
          table[col][3] = j;
        } else {
          table[col][0] = std::min(i, table[col][0]);
          table[col][1] = std::max(j, table[col][1]);
          table[col][2] = std::max(i, table[col][2]);
          table[col][3] = std::min(j, table[col][3]);
        }
      }
    }
    bool result = true;
    for (int i = 0; i < 61; i++) {
      if (seen[i] == -1) continue;
      if (seen[i] == 0) {
        result = dfs(i);
        if (result == 0) return false;
      }
    }
    return true;
  }
};
