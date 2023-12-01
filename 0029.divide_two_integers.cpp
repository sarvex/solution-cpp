#include <cmath>
#include <cstdint>

class Solution {
public:
  static int divide(const int a, const int b) {
    auto sign = 1;
    if (a < 0 xor b < 0) {
      sign = -1;
    }

    auto x = std::abs(static_cast<long long>(a));
    auto y = std::abs(static_cast<long long>(b));
    auto total = 0ll;
    while (x >= y) {
      auto count = 0;
      while (x >= (y << (count + 1))) {
        ++count;
      }
      total += 1ll << count;
      x -= y << count;
    }

    if (const auto result = sign * total;
      result >= std::numeric_limits<int32_t>::min() and result <= std::numeric_limits<int32_t>::max()) {
      return static_cast<int>(result);
    }
    return std::numeric_limits<int32_t>::max();
  }
};
