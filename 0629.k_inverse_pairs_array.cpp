#include <algorithm>
#include <vector>

class Solution {
public:
  auto kInversePairs(const int n, const int k) {
    constexpr int mod = 1e9 + 7;
    std::vector result(k + 1, 0);
    std::vector s(k + 2, 1);
    result[0] = 1;
    s[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) result[j] = (s[j + 1] - s[std::max(0, j - (i - 1))] + mod) % mod;
      for (int j = 1; j <= k + 1; ++j) s[j] = (s[j - 1] + result[j - 1]) % mod;
    }
    return result[k];
  }
};
