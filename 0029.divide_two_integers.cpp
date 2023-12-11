#include <cmath>
#include <cstdint>
#include <limits>

using std::abs;
using std::numeric_limits;


class Solution {
public:
  auto divide(const int a, const int b) {
    auto sign = 1;
    if (a < 0 xor b < 0) {
      sign = -1;
    }

    auto x = abs(static_cast<int16_t>(a));
    auto y = abs(static_cast<int16_t>(b));
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
      result >= numeric_limits<int32_t>::min() and result <= numeric_limits<int32_t>::max()) {
      return static_cast<int>(result);
    }
    return numeric_limits<int32_t>::max();
  }
};
