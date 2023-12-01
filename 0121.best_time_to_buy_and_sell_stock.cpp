#include <vector>
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    auto result = 0;
    auto low = prices[0];
    for (auto value : prices) {
      result = std::max(result, value - low);
      low = std::min(low, value);
    }
    return result;
  }
};
