#include <functional>
#include <vector>

class Solution {
public:
  int numWaysFast(int steps, const int arrLen) {
    constexpr auto mod = 1000000007;
    const int max_position = std::min(steps / 2 + 1, arrLen);

    std::vector current(max_position + 2, 0);
    std::vector next(max_position + 2, 0);
    current[1] = 1;

    while (steps > 0) {
      for (int pos = 1; pos <= max_position; pos++) {
        next[pos] = (static_cast<long>(current[pos]) + current[pos - 1] + current[pos + 1]) % mod;
      }

      swap(current, next);
      steps--;
    }

    return current[1];
  }

  auto numWays(const int steps, const int arrLen) {
    std::vector f(steps, std::vector(steps + 1, -1));
    constexpr int mod = 1e9 + 7;
    std::function<int(int, int)> search = [&](const int i, const int j) -> int {
      if (i > j or i >= arrLen or i < 0 or j < 0) return 0;
      if (i == 0 and j == 0) return 1;
      if (f[i][j] != -1) return f[i][j];
      int result = 0;
      for (int k = -1; k <= 1; ++k) { result = (result + search(i + k, j - 1)) % mod; }
      return f[i][j] = result;
    };
    return search(0, steps);
  }
};
