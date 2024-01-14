#include <deque>
#include <vector>

class Solution {
public:
  int minCost(std::vector<std::vector<int>>& grid) {
    const int m = static_cast<int>(grid.size()), n = static_cast<int>(grid[0].size());
    std::vector seen(m, std::vector<bool>(n));
    const std::vector<std::vector<int>> dirs{ { 0, 0 }, { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    std::deque<std::pair<int, int>> q;
    q.emplace_back(0, 0);
    while (not q.empty()) {
      auto p = q.front();
      q.pop_front();
      const int i = p.first / n, j = p.first % n, d = p.second;
      if (i == m - 1 and j == n - 1) return d;
      if (seen[i][j]) continue;
      seen[i][j] = true;
      for (int k = 1; k <= 4; ++k) {
        if (const int x = i + dirs[k][0], y = j + dirs[k][1]; x >= 0 and x < m and y >= 0 and y < n) {
          if (grid[i][j] == k)
            q.emplace_front(x * n + y, d);
          else
            q.emplace_back(x * n + y, d + 1);
        }
      }
    }
    return -1;
  }
};
