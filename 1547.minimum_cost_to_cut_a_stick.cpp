#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  auto minCostFast(const int n, std::vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    std::ranges::sort(cuts);
    const auto m = cuts.size();
    constexpr auto mx = std::numeric_limits<int>::max();
    std::vector result(m, std::vector(m, 0)), dp(m, std::vector(m, 0));
    for (int i = m - 1; i >= 0; i--) {
      for (int j = i; j < m; j++) {
        result[i][j] = mx;
        if (i == j or i + 1 == j) {
          result[i][j] = 0;
          dp[i][j] = i;
          continue;
        }
        int mn = mx;
        for (int k = dp[i][j - 1]; k <= std::ranges::min(j - 1, dp[i + 1][j]); k++) {
          if (mn > result[i][k] + result[k][j]) {
            mn = result[i][k] + result[k][j];
            dp[i][j] = k;
          }
        }
        result[i][j] = mn + cuts[j] - cuts[i];
      }
    }
    return result[0][m - 1];
  }

  auto minCost(const int n, std::vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    std::ranges::sort(cuts);
    const auto m = cuts.size();
    std::vector result(m, std::vector(m, 0));
    for (int l = 2; l < m; ++l) {
      for (int i = 0; i + l < m; ++i) {
        const int j = i + l;
        result[i][j] = 1 << 30;
        for (int k = i + 1; k < j; ++k)
          result[i][j] = std::min(result[i][j], result[i][k] + result[k][j] + cuts[j] - cuts[i]);
      }
    }
    return result[0][m - 1];
  }
};
