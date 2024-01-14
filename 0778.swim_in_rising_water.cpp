#include <vector>

class Solution {
public:
  std::vector<int> p;

  int swimInWater(const std::vector<std::vector<int>>& grid) {
    const int n = grid.size();
    p.resize(n * n);
    for (int i = 0; i < p.size(); ++i) p[i] = i;
    std::vector<int> hi(n * n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        hi[grid[i][j]] = i * n + j;
    const std::vector dirs = {-1, 0, 1, 0, -1};
    for (int t = 0; t < n * n; ++t) {
      const int i = hi[t] / n, j = hi[t] % n;
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k], y = j + dirs[k + 1];
        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t)
          p[find(x * n + y)] = find(hi[t]);
        if (find(0) == find(n * n - 1)) return t;
      }
    }
    return -1;
  }

  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }
};
