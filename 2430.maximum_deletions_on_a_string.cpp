#include <string>
#include <vector>

class Solution {
public:
  auto deleteString(const std::string& s) {
    const auto n = static_cast<int>(s.size());
    std::vector g(n + 1, std::vector(n + 1, 0));
    for (int i = n - 1; ~i; --i) { for (int j = i + 1; j < n; ++j) if (s[i] == s[j]) g[i][j] = g[i + 1][j + 1] + 1; }
    std::vector result(n, 1);
    for (int i = n - 1; ~i; --i) {
      for (int j = 1; j <= (n - i) / 2; ++j) if (g[i][i + j] >= j) result[i] = std::max(result[i], result[i + j] + 1);
    }
    return result[0];
  }
};
