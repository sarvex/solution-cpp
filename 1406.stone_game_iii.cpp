#include <functional>
#include <string>

class Solution {
public:
  auto stoneGameIII(const std::vector<int>& stoneValue) -> std::string {
    const auto n = stoneValue.size();
    constexpr int inf = 0x3f3f3f3f;
    constexpr int neg = -(1 << 30);
    std::vector f(n, inf);
    const std::function<int(int)> search = [&](const int i) -> int {
      if (i >= n) return 0;
      if (f[i] != inf) return f[i];
      int result = neg, s = 0;
      for (int j = 0; j < 3 and i + j < n; ++j) {
        s += stoneValue[i + j];
        result = std::max(s - search(i + j + 1), result);
      }
      return f[i] = result;
    };
    const int result = search(0);
    if (result == 0) return "Tie";
    return result > 0 ? "Alice" : "Bob";
  }
};
