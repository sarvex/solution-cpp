#include <algorithm>
#include <cstdint>
#include <limits>
#include <vector>

class Solution {
public:
  int findMinArrowShots(std::vector<std::vector<int>>& points) {
    sort( points.begin(), points.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) { return a[1] < b[1]; });
    int result = 0;
    int64_t last = std::numeric_limits<int64_t>::min();
    for (auto& p: points) {
      if (p[0] > last) {
        ++result;
        last = p[1];
      }
    }
    return result;
  }
};
