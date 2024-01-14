#include <cstdint>
#include <functional>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  auto longestSquareStreak(const std::vector<int>& nums) {
    const std::unordered_set<int64_t> s(nums.begin(), nums.end());
    std::unordered_map<int64_t, int64_t> table;
    int64_t result = 0;
    std::function<int64_t(int64_t)> search = [&](const int64_t x) {
      if (not s.contains(x)) return 0;
      if (table.contains(x)) return table[x];
      if (x * x > std::numeric_limits<int>::max()) return 1;
      table[x] = 1 + search(x * x);
      return table[x];
    };
    for (const int& num : nums) result = std::max(result, search(num));
    return result < 2 ? -1 : static_cast<int>(result);
  }
};
