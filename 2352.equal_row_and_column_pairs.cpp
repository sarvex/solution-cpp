#include <vector>

class Solution {
public:
  int equalPairs(const std::vector<std::vector<int>>& grid) {
    const int n = grid.size();
    std::vector transpose(n, std::vector<int>(n));
    for (int j = 0; j < n; ++j) for (int i = 0; i < n; ++i) transpose[i][j] = grid[j][i];
    int result = 0;
    for (auto& row: grid) for (auto& col: transpose) result += row == col;
    return result;
  }
};
