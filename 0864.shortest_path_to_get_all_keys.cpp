#include <queue>
#include <string>
#include <vector>

class Solution {
public:


  int shortestPathAllKeys(std::vector<std::string>& grid) {
    const std::vector dirs = { -1, 0, 1, 0, -1 };
    const int m = grid.size(), n = grid[0].size();
    int k = 0, si = 0, sj = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (const char c = grid[i][j]; islower(c)) ++k;
        else if (c == '@') si = i, sj = j;
      }
    }
    std::queue<std::tuple<int, int, int>> q{ { { si, sj, 0 } } };
    std::vector seen(m, std::vector (n, std::vector<bool>(1 << k)));
    seen[si][sj][0] = true;
    int result = 0;
    while (not q.empty()) {
      for (int t = q.size(); t; --t) {
        auto [i, j, state] = q.front();
        q.pop();
        if (state == (1 << k) - 1) return result;
        for (int h = 0; h < 4; ++h) {
          if (const int x = i + dirs[h], y = j + dirs[h + 1]; x >= 0 and x < m and y >= 0 and y < n) {
            const char c = grid[x][y];
            if (c == '#' or (isupper(c) and (state >> (c - 'A') & 1) == 0)) continue;
            int nxt = state;
            if (islower(c)) nxt |= 1 << (c - 'a');
            if (not seen[x][y][nxt]) {
              seen[x][y][nxt] = true;
              q.emplace( x, y, nxt );
            }
          }
        }
      }
      ++result;
    }
    return -1;
  }
};
