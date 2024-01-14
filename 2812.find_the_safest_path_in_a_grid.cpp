#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
  int maximumSafenessFactor(const std::vector<std::vector<int>>& grid) {
    const int n = static_cast<int>(grid.size());
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) { return 0; }

    const int maxdist = n - 1 << 1;
    std::vector mindist(n, std::vector<int>(n));
    mindist[0][0] = (grid[0][0]) ? 0 : maxdist;
    for (int i = 1; i < n; i++) {
      mindist[0][i] = grid[0][i] ? 0 : std::min(mindist[0][i - 1] + 1, maxdist);
      mindist[i][0] = grid[i][0] ? 0 : std::min(mindist[i - 1][0] + 1, maxdist);
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < n; j++) {
        mindist[i][j] = grid[i][j] ? 0 : std::min(mindist[i - 1][j] + 1, mindist[i][j - 1] + 1);
      }
    }

    for (int i = n - 2; i >= 0; i--) {
      mindist[n - 1][i] = std::min(mindist[n - 1][i + 1] + 1, mindist[n - 1][i]);
      mindist[i][n - 1] = std::min(mindist[i + 1][n - 1] + 1, mindist[i][n - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
      for (int j = n - 2; j >= 0; j--) {
        mindist[i][j] = std::min({ mindist[i][j], mindist[i + 1][j] + 1, mindist[i][j + 1] + 1 });
      }
    }
    std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
    std::vector seen(n, std::vector(n, false));
    int result = 0;
    pq.push({ mindist[0][0], { 0, 0 } });
    seen[0][0] = true;

    while (not pq.empty()) {
      int val = pq.top().first;
      int x = pq.top().second.first;
      int y = pq.top().second.second;
      pq.pop();

      if (x == n - 1 and y == n - 1) {
        result = val;
        break;
      }

      if (x > 0 and not seen[x - 1][y]) {
        seen[x - 1][y] = true;
        pq.push({ std::min(val, mindist[x - 1][y]), { x - 1, y } });
      }
      if (y > 0 and not seen[x][y - 1]) {
        seen[x][y - 1] = true;
        pq.push({ std::min(val, mindist[x][y - 1]), { x, y - 1 } });
      }
      if (x < n - 1 and not seen[x + 1][y]) {
        seen[x + 1][y] = true;
        pq.push({ std::min(val, mindist[x + 1][y]), { x + 1, y } });
      }
      if (y < n - 1 and not seen[x][y + 1]) {
        seen[x][y + 1] = true;
        pq.push({ std::min(val, mindist[x][y + 1]), { x, y + 1 } });
      }
    }

    return result;
  }
};
