#include <algorithm>
#include <cstdint>
#include <vector>

class Solution {
public:
  auto maxIncreasingGroups(std::vector<int>& usageLimits) {
    std::ranges::sort(usageLimits);
    int result = 0;
    int64_t sum = 0;
    for (const int usage: usageLimits) {
      sum += usage;
      if (sum > result) {
        ++result;
        sum -= result;
      }
    }
    return result;
  }
};
