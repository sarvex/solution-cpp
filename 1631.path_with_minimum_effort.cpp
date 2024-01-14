#include <cmath>
#include <queue>
#include <vector>

class Solution {
public:
  auto minimumEffortPath(const std::vector<std::vector<int>>& heights) {
    const auto m = heights.size(), n = heights[0].size();
    std::vector result(m, std::vector(n, std::numeric_limits<int>::max() >> 2));
    result[0][0] = 0;
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> q;
    q.emplace(0, 0, 0);
    const std::vector dirs = { -1, 0, 1, 0, -1 };
    while (not q.empty()) {
      auto [t, i, j] = q.top();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        if (const int x = i + dirs[k], y = j + dirs[k + 1]; x >= 0 and x < m and y >= 0 and y < n) {
          if (const int nd = std::max(t, std::abs(heights[x][y] - heights[i][j])); nd < result[x][y]) {
            result[x][y] = nd;
            q.emplace(nd, x, y);
          }
        }
      }
    }
    return result[m - 1][n - 1];
  }
};
