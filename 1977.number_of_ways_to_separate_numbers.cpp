#include <string>
#include <vector>

class Solution {
public:
  const int mod = 1e9 + 7;

  auto numberOfCombinations(const std::string& num) {
    const auto n = num.size();
    std::vector lcp(n + 1, std::vector<int>(n + 1));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) { if (num[i] == num[j]) { lcp[i][j] = 1 + lcp[i + 1][j + 1]; } }
    }
    auto cmp = [&](int i, int j, int k) {
      const int x = lcp[i][j];
      return x >= k or num[i + x] >= num[j + x];
    };
    std::vector result(n + 1, std::vector<int>(n + 1));
    result[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        int v = 0;
        if (num[i - j] != '0') {
          if (i - j - j >= 0 and cmp(i - j, i - j - j, j)) { v = result[i - j][j]; } else {
            v = result[i - j][std::min(j - 1, i - j)];
          }
        }
        result[i][j] = (result[i][j - 1] + v) % mod;
      }
    }
    return result[n][n];
  }
};
