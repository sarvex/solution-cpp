#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
  auto minSideJumps(const std::vector<int>& obstacles) {
    const auto n = obstacles.size();
    constexpr int inf = std::numeric_limits<int>::max() >> 2;
    std::vector f{ 1, 0, 1 };
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 3; ++j)
        if (obstacles[i] == j + 1) {
          f[j] = inf;
          break;
        }
      int x = std::min({ f[0], f[1], f[2] }) + 1;
      for (int j = 0; j < 3; ++j) if (obstacles[i] != j + 1) f[j] = std::min(f[j], x);
    }
    return std::min({ f[0], f[1], f[2] });
  }
};
