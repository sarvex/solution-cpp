#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  auto largestAltitudeFast(const std::vector<int>& gain) {
    std::vector result(gain.size() + 1, 0);
    inclusive_scan(gain.cbegin(), gain.cend(), result.begin(), std::plus{});
    return *max_element(result.cbegin(), result.cend());
  }

  auto largestAltitude(const std::vector<int>& gain) {
    int result = 0, height = 0;
    for (auto& elem: gain) {
      height += elem;
      result = std::max(result, height);
    }
    return result;
  }
};
