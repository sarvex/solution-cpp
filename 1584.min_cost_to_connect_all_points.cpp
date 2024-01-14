#include <cmath>
#include <vector>

class Solution {
public:
  auto minCostConnectPoints(const std::vector<std::vector<int>>& points) {
    const auto n = points.size();
    std::vector g(n, std::vector(n, 0));
    for (int i = 0; i < n; ++i) {
      const int x1 = points[i][0], y1 = points[i][1];
      for (int j = i + 1; j < n; ++j) {
        const int x2 = points[j][0], y2 = points[j][1];
        const int t = abs(x1 - x2) + abs(y1 - y2);
        g[i][j] = t;
        g[j][i] = t;
      }
    }
    std::vector dist(n, std::numeric_limits<int>::max());
    std::vector seen(n, false);
    dist[0] = 0;
    int result = 0;
    for (int i = 0; i < n; ++i) {
      int j = -1;
      for (int k = 0; k < n; ++k) if (not seen[k] and (j == -1 or dist[k] < dist[j])) j = k;
      seen[j] = true;
      result += dist[j];
      for (int k = 0; k < n; ++k) if (not seen[k]) dist[k] = std::min(dist[k], g[j][k]);
    }
    return result;
  }
};
