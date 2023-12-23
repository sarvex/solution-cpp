#include <vector>
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    if (prices.size() < 2) return 0;

    auto result = 0;
    auto low = prices[0];
    for (auto price : prices) {
      result = std::max(result, price - low);
      low = std::min(low, price);
    }
    return result;
  }
};
