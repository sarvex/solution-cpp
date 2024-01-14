#include <cstdint>
#include <vector>

class Solution {
  auto getMaxFunctionValue(const std::vector<int>& receiver, const uint64_t k) {
    const int n = static_cast<int>(receiver.size()), m = 64 - std::countl_zero(k);
    std::vector f(n, std::vector(m, 0));
    std::vector g(n, std::vector(m, 0LL));
    for (int i = 0; i < n; ++i) {
      f[i][0] = receiver[i];
      g[i][0] = i;
    }
    for (int j = 1; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        f[i][j] = f[f[i][j - 1]][j - 1];
        g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];
      }
    }
    int64_t result = 0;
    for (int i = 0; i < n; ++i) {
      int p = i;
      int64_t t = 0;
      for (int j = 0; j < m; ++j) {
        if (k >> j & 1) {
          t += g[p][j];
          p = f[p][j];
        }
      }
      result = std::max(result, p + t);
    }
    return result;
  }
};
