#include <numeric>
#include <vector>

class Solution {
public:
  int stoneGameVIII(const std::vector<int>& stones) {
    std::partial_sum(std::cbegin(stones), std::cend(stones), std::begin(stones));

    return std::reduce(
        std::next(std::crbegin(stones)), std::prev(std::crend(stones)), stones.back(), [](const auto& x, auto sum) {
          return std::max(x, sum - x);
        });
  }

  auto stoneGameVIII(std::vector<int>& stones) {
    const auto n = static_cast<int>(stones.size());
    for (int i = 1; i < n; ++i) stones[i] += stones[i - 1];
    int result = stones.back();
    for (int i = n - 2; i; --i) result = std::max(stones[i] - result, result);
    return result;
  }
};
