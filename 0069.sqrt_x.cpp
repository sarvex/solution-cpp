#include <cstdint>

class Solution {
public:
  auto mySqrt(const int x) {
    uint64_t left = 0, right = x;
    while (left < right) {
      uint64_t mid = left + ((right - left + 1) >> 1);
      if (mid <= x / mid)
        left = mid;
      else
        right = mid - 1;
    }
    return static_cast<int>(left);
  }
};
