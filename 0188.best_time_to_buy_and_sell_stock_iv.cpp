#include <algorithm>
#include <vector>

class Solution {
public:
  int maxProfit(const int k, const std::vector<int>& prices) {
    const int n = prices.size();
    std::vector f(k + 1, std::vector(2, 0));
    for (int j = 1; j <= k; ++j) { f[j][1] = -prices[0]; }
    for (int i = 1; i < n; ++i) {
      for (int j = k; j; --j) {
        f[j][0] = std::max(f[j][1] + prices[i], f[j][0]);
        f[j][1] = std::max(f[j - 1][0] - prices[i], f[j][1]);
      }
    }
    return f[k][0];
  }
};
