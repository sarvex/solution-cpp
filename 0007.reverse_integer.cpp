#include <limits>

class Solution {
public:
  auto reverse(int x) {
    auto result = 0;
    for (; x; x /= 10) {
      if (result < std::numeric_limits<int>::min() / 10 or result > std::numeric_limits<int>::max() / 10) {
        return 0;
      }
      result = result * 10 + x % 10;
    }
    return result;
  }
};
