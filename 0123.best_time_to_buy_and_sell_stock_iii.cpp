#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    int f1 = -prices[0], f2 = 0, f3 = -prices[0], f4 = 0;
    for (int i = 1; i < prices.size(); ++i) {
      f1 = std::max(f1, -prices[i]);
      f2 = std::max(f2, f1 + prices[i]);
      f3 = std::max(f3, f2 - prices[i]);
      f4 = std::max(f4, f3 + prices[i]);
    }
    return f4;
  }
};
