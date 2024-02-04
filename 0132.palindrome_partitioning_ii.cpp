#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
  int minCut(const std::string& s) {
    const auto n = static_cast<int>(s.size());
    std::vector g(n, std::vector(n, true));
    for (int i = n - 1; ~i; --i)
      for (int j = i + 1; j < n; ++j) g[i][j] = s[i] == s[j] and g[i + 1][j - 1];

    std::vector<int> f(n);
    iota(f.begin(), f.end(), 0);
    for (int i = 1; i < n; ++i)
      for (int j = 0; j <= i; ++j)
        if (g[j][i]) f[i] = std::min(f[i], j ? 1 + f[j - 1] : 0);
    return f[n - 1];
  }
};
