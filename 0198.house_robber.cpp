#include <vector>

class Solution {
public:
  auto rob(const std::vector<int>& nums) {
    int result = 0, last = 0;
    for (auto& x: nums) {
      const int mx = std::max(result, last);
      last = result + x;
      result = mx;
    }
    return std::max(result, last);
  }
};
