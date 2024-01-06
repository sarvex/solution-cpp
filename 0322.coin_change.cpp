#include <vector>

class Solution {
public:
  int coinChange(const std::vector<int>& coins, const int amount) {
    const int n = amount;
    std::vector result(n + 1, std::numeric_limits<int>::max() - 1);
    result[0] = 0;
    for (auto& coin: coins) for (int j = coin; j <= n; ++j) result[j] = std::min(result[j], result[j - coin] + 1);
    return result[n] > n ? -1 : result[n];
  }
};
