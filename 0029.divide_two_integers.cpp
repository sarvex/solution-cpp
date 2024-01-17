#include <cmath>
#include <cstdint>

class Solution {
public:
  auto divide(const int a, const int b) const {
    auto sign = 1;
    if (a < 0 xor b < 0) { sign = -1; }

    int64_t x = abs(a), y = abs(b), total = 0LL;
    while (x >= y) {
      auto count = 0;
      while (x >= (y << (count + 1))) { ++count; }
      total += 1LL << count;
      x -= y << count;
    }

    if (const auto result = sign * total;
      result >= std::numeric_limits<int32_t>::min() and result <= std::numeric_limits<int32_t>::max()) {
      return static_cast<int>(result);
    }
    return std::numeric_limits<int32_t>::max();
  }
};
