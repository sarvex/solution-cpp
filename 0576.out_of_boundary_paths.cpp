#include <functional>
#include <vector>

class Solution {
public:
  int findPaths(const int m, const int n, const int maxMove, const int startRow, const int startColumn) {
    constexpr int mod = 1e9 + 7;
    std::vector f(51, std::vector(51, std::vector(51, -1)));
    const std::vector dirs { -1, 0, 1, 0, -1 };

    std::function<int(int i, int j, int k)> search = [&](const int i, const int j, const int k) {
      if (i < 0 or i >= m or j < 0 or j >= n) return 1;
      if (f[i][j][k] != -1) return f[i][j][k];
      if (k == 0) return 0;
      int result = 0;
      for (int t = 0; t < 4; ++t) {
        const int x = i + dirs[t], y = j + dirs[t + 1];
        result += search(x, y, k - 1);
        result %= mod;
      }
      return f[i][j][k] = result;
    };

    return search(startRow, startColumn, maxMove);
  }
};
