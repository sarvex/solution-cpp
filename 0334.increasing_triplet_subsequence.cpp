#include <limits>
#include <vector>

class Solution {
public:
  bool increasingTriplet(const std::vector<int>& nums) {
    int mi = std::numeric_limits<int>::max(), mid = std::numeric_limits<int>::max();
    for (auto& num: nums) {
      if (num > mid) return true;
      if (num <= mi) mi = num;
      else mid = num;
    }
    return false;
  }
};
